#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(void)
{
	HANDLE hFile = CreateFile(_T("ABC.DAT"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	_tprintf(_T("error code: %d\n"), GetLastError());

	hFile = CreateFile(_T("ABC2.DAT"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	_tprintf(_T("error code: %d\n"), GetLastError());

	return 0;
}