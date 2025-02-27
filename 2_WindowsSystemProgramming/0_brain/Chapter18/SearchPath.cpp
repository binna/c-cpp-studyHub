#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	TCHAR fileName[MAX_PATH];
	TCHAR bufFilePath[MAX_PATH];
	LPTSTR lpFilePart;
	DWORD result;

	_tprintf(_T("Insert name of the file to find : "));
	_tscanf_s(_T("%s"), fileName, MAX_PATH);

	result = SearchPath(NULL, fileName, NULL, MAX_PATH, bufFilePath, &lpFilePart);

	if (result == 0)
		_tprintf(_T("File not found!\n"));
	else
	{
		_tprintf(_T("File path : %s\n"), bufFilePath);
		_tprintf(_T("File name only : %s\n"), lpFilePart);
	}

	return 0;
	return 0;
}