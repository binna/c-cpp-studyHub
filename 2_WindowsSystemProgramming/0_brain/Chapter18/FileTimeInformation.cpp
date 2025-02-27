#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define STRING_LEN		100

int _tmain(void)
{
	TCHAR fileName[] = _T("data.txt");

	TCHAR fileCreateTimeInfo[STRING_LEN];
	TCHAR fileAccessTimeInfo[STRING_LEN];
	TCHAR fileWriteTimeInfo[STRING_LEN];

	FILETIME ftCreate, ftAccess, ftWrite;

	SYSTEMTIME stCreateUTC, stCreateLocal;
	SYSTEMTIME stAccessUTC, stAccessLocal;
	SYSTEMTIME stWriteUTC, stWriteLocal;

	HANDLE hFile = CreateFile(
		fileName, 
		GENERIC_READ, 
		0, 
		0, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("GetFileTime function call fault!\n"));
		return -1;
	}

	// 파일의 시간 정보 추출
	if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
	{
		_tprintf(_T("GetFileTime function call fault!\n"));
		return FALSE;
	}

	// 시간 정보 변환 - create
	FileTimeToSystemTime(&ftCreate, &stCreateUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stCreateUTC, &stCreateLocal);

	// 시간 정보 변환 - access
	FileTimeToSystemTime(&ftAccess, &stAccessUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stAccessUTC, &stAccessLocal);

	// 시간 정보 변환 - write
	FileTimeToSystemTime(&ftWrite, &stWriteUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stWriteUTC, &stWriteLocal);

	_stprintf_s(
		fileCreateTimeInfo, 
		_T("%02d/%02d/%d %02d:%02d"), 
		stCreateLocal.wMonth,
		stCreateLocal.wDay,
		stCreateLocal.wYear,
		stCreateLocal.wHour,
		stCreateLocal.wMinute);

	_stprintf_s(
		fileAccessTimeInfo, 
		_T("%02d/%02d/%d %02d:%02d"),
		stAccessLocal.wMonth,
		stAccessLocal.wDay,
		stAccessLocal.wYear,
		stAccessLocal.wHour,
		stAccessLocal.wMinute);

	_stprintf_s(
		fileWriteTimeInfo,
		_T("%02d/%02d/%d %02d:%02d"), 
		stWriteLocal.wMonth,
		stWriteLocal.wDay,
		stWriteLocal.wYear,
		stWriteLocal.wHour,
		stWriteLocal.wMinute);

	_tprintf(_T("File create time : %s\n"), fileCreateTimeInfo);
	_tprintf(_T("File accessed time : %s\n"), fileAccessTimeInfo);
	_tprintf(_T("File written time : %s\n"), fileWriteTimeInfo);

	CloseHandle(hFile);

	return 0;
}