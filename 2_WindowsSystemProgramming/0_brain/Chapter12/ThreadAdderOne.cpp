#include <stdio.h>
#include <tchar.h>
#include <windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD numOne = *nPtr;
	DWORD numTwo = *(nPtr + 1);

	DWORD total = 0;
	for (DWORD i = numOne; i <= numTwo; i++)
	{
		total += i;
	}

	return total;
}

int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[] = { 1,3,4,7,8,10 };
	DWORD total = 0;
	DWORD result = 0;

	hThread[0] = CreateThread(
		NULL,
		0,
		ThreadProc,
		(LPVOID)(&paramThread[0]),
		0,
		&dwThreadID[0]);

	hThread[1] = CreateThread(
		NULL,
		0,
		ThreadProc,
		(LPVOID)(&paramThread[2]),
		0,
		&dwThreadID[1]);

	hThread[2] = CreateThread(
		NULL,
		0,
		ThreadProc,
		(LPVOID)(&paramThread[4]),
		0,
		&dwThreadID[2]);

	if (hThread[0] == NULL || hThread[1] == NULL || hThread[2] == NULL)
	{
		_tprintf(_T("Thread creation fault!\n"));
		return -1;
	}

	WaitForMultipleObjects(
		3,				// 총 3개의 커널 오브젝트를 관찰
		hThread,		// 커널 오브젝트 핸들의 배열 정보
		TRUE,			// 모든 커널 오브젝트가 signaled 상태가 되기를
		INFINITE);		// 영원히 기다린다

	GetExitCodeThread(hThread[0], &result);
	total += result;

	GetExitCodeThread(hThread[1], &result);
	total += result;

	GetExitCodeThread(hThread[2], &result);
	total += result;

	_tprintf(_T("total(1 ~ 10) : %d\n"), total);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	return 0;
}