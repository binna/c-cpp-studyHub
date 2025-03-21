#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define BUFSIZE 1024

int _tmain(int argc, TCHAR* argv[])
{
	TCHAR value[BUFSIZE];

	if (GetEnvironmentVariable(_T("Good"), value, BUFSIZ) > 0)
		_tprintf(_T("[%s = %s]\n"), _T("Good"), value);

	if (GetEnvironmentVariable(_T("Hey"), value, BUFSIZ) > 0)
		_tprintf(_T("[%s = %s]\n"), _T("Hey"), value);

	if (GetEnvironmentVariable(_T("Big"), value, BUFSIZ) > 0)
		_tprintf(_T("[%s = %s]\n"), _T("Big"), value);

	Sleep(10000);
	return 0;
}