#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define _WIN32_WINNT		0x0400


int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hTimer = NULL;
	LARGE_INTEGER liDueTime;

	liDueTime.QuadPart = -100000000;

	// 타이머 오브젝트 생성
	hTimer = CreateWaitableTimer(NULL, FALSE, _T("WaitableTimer"));

	if (!hTimer)
	{
		_tprintf(_T("CreateWaitableTimer failed(%d)\n"), GetLastError());
		return 1;
	}

	_tprintf(_T("CreateWait for 5 seconds ...\n"));

	// 타이머의 알람을 5초로 설정
	SetWaitableTimer(hTimer, &liDueTime, 5000, NULL, NULL, FALSE);

	// 타이머의 알람 대기
	while (1)
	{
		WaitForSingleObject(hTimer, INFINITE);
		_tprintf(_T("Timer was signaled.\n"));
		MessageBeep(MB_ICONEXCLAMATION);
	}

	return 0;
}