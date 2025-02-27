#include <stdio.h>
#include <tchar.h>
#include <windows.h>

void ShowAttributes(DWORD attrib);

int _tmain(int argc, TCHAR* argv[])
{
	TCHAR filename[] = _T("data.txt");

	_tprintf(_T("Original file attributes \n"));
	DWORD attrib = GetFileAttributes(filename);
	ShowAttributes(attrib);

	attrib |= (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes(filename, attrib);

	_tprintf(_T("Change file attributes \n"));
	attrib = GetFileAttributes(filename);
	ShowAttributes(attrib);

	attrib &= ~(FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes(filename, attrib);

	_tprintf(_T("Rollback file attributes \n"));
	attrib = GetFileAttributes(filename);
	ShowAttributes(attrib);

	return 0;
}

void ShowAttributes(DWORD attrib)
{
	if (attrib & FILE_ATTRIBUTE_NORMAL)
	{
		_tprintf(_T("Normal\n"));
	}
	else
	{
		if (attrib & FILE_ATTRIBUTE_READONLY)
			_tprintf(_T("Read Only\n"));

		if (attrib & FILE_ATTRIBUTE_HIDDEN)
			_tprintf(_T("Hidden\n"));
	}
	_tprintf(_T("\n"));
}