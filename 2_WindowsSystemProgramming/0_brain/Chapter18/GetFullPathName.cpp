#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define STRING_LEN		200

int _tmain(int argc, TCHAR* argv[])
{
	TCHAR fileName[] = _T("data.txt");
	TCHAR fileFullPathName[STRING_LEN];
	LPTSTR filePtr;

	DWORD result = GetFullPathName(fileName, STRING_LEN, fileFullPathName, &filePtr);
	if (result == 0) {
		_tprintf(_T("GetFullPathName 실패! 오류 코드: %d\n"), GetLastError());
		return -1;
	}

	_tprintf(_T("|%s|\n"), fileFullPathName);
	_tprintf(_T("|%s|\n"), filePtr);

	return 0;
}