#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	DWORD state;

	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;

	LPCWSTR title = _T("return & exit");
	si.lpTitle = (LPWSTR)malloc((_tcslen(title) + 1) * sizeof(TCHAR));

	if (si.lpTitle == NULL)
		return -1;
	
	_tcscpy_s(si.lpTitle, _tcslen(title) + 1, title);

	TCHAR command[] = _T("exe/OperationStateChild.exe");

	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	for (DWORD i = 0; i < 10000; i++)		// Child Process의 우선 종료를 위해
		for (DWORD i = 0; i < 10000; i++);

	GetExitCodeProcess(pi.hProcess, &state);

	if (state == STILL_ACTIVE)
		_tprintf(_T("STILL_ACTIVE\n\n"));
	else
		_tprintf(_T("state : %d\n\n"), state);

	return 0;
}