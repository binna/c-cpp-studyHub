#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	// 파일 핸들 생성
	HANDLE hFile = CreateFile(
		_T("data.dat"),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		_tprintf(_T("Could not open file."));

	TCHAR fileData[] = _T("Best test string~ ^^");
	DWORD numOfByteWritten = 0;
	WriteFile(
		hFile,
		fileData,
		sizeof(fileData),
		&numOfByteWritten,
		NULL);

	// 파일 연결 오브젝트 생성
	HANDLE hMapFile = CreateFileMapping(
		hFile,
		NULL,
		PAGE_READONLY,
		0,
		0,
		NULL);

	if (hMapFile == NULL)
		_tprintf(_T("Could not create map of file.\n"));

	// 메모리 연결
	TCHAR* pWrite = (TCHAR*)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 0);

	if (pWrite == NULL)
		_tprintf(_T("Could not map view of file.\n"));

	_tprintf(_T("String in file: %s\n"), pWrite);

	UnmapViewOfFile(hFile);
	CloseHandle(hMapFile);

	CloseHandle(hFile);
	_tprintf(_T("End of process!\n"));
	return 0;
}