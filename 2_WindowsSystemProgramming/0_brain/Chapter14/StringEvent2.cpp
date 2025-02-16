#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <process.h>

unsigned int WINAPI OutputThreadFunction(LPVOID lpParam);
unsigned int WINAPI CountThreadFunction(LPVOID lpParam);

TCHAR string[100];
HANDLE hEvent;

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hThread[2];
	DWORD dwThreadIDs[2];

	hEvent = CreateEvent(	// event object 생성
		NULL,	// 상속 불가
		TRUE,	// manual-reset mode로 생성
		FALSE,	// non-signaled 상태로 생성
		NULL);	// 이름없는 event

	if (hEvent == NULL)
	{
		_fputts(_T("Event object creation error\n"), stdout);
		return -1;
	}

	hThread[0] = (HANDLE)_beginthreadex(
		NULL,
		0,
		OutputThreadFunction,
		NULL,
		0,
		(unsigned*)&dwThreadIDs[0]);

	hThread[1] = (HANDLE)_beginthreadex(
		NULL,
		0,
		CountThreadFunction,
		NULL,
		0,
		(unsigned*)&dwThreadIDs[1]);

	if (hThread[0] == 0 || hThread[1] == 0)
	{
		_fputts(_T("Thread creation error\n"), stdout);
		return -1;
	}

	_fputts(_T("Insert string : "), stdout);
	_fgetts(string, 30, stdin);

	SetEvent(hEvent);			// event의 state를 signaled 상태로 변경

	WaitForMultipleObjects(
		2,			// 배열의 길이
		hThread,	// 핸들의 배열
		TRUE,		// 모든 핸들이 신호받는 상태로 될 때, 리턴
		INFINITE);	// 무한 대기

	CloseHandle(hEvent);		// event 오브젝트 소멸
	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	return 0;
}

unsigned int __stdcall OutputThreadFunction(LPVOID lpParam)
{
	WaitForSingleObject(hEvent, INFINITE);

	_fputts(_T("Output string : "), stdout);
	_fputts(string, stdout);

	return 0;
}

unsigned int __stdcall CountThreadFunction(LPVOID lpParam)
{
	WaitForSingleObject(hEvent, INFINITE);

	_tprintf(_T("output string length : %d\n"), _tcslen(string) - 1);

	return 0;
}