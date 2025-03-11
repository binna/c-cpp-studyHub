#include <stdio.h>
#include <tchar.h>
#include <windows.h>

TCHAR strData[] =
	_T("1. one\n")
	_T("2. two\n")
	_T("3. three\n")
	_T("4. four\n")
	_T("5. five\n");

VOID WINAPI FileIOCompletionRoutine(DWORD, DWORD, LPOVERLAPPED);

int _tmain(int argc, TCHAR* argv[])
{
	TCHAR fileName[] = _T("data.txt");
	HANDLE hFile = CreateFile(
		fileName, 
		GENERIC_WRITE, 
		FILE_SHARE_WRITE, 
		0, 
		CREATE_ALWAYS, 
		FILE_FLAG_OVERLAPPED, 
		0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File creation fault!\n"));
		return -1;
	}

	OVERLAPPED overlappedInst;
	memset(&overlappedInst, 0, sizeof(overlappedInst));
	overlappedInst.hEvent = (HANDLE)1234;
	WriteFileEx(hFile, strData, sizeof(strData), &overlappedInst, FileIOCompletionRoutine);

	//SleepEx(INFINITE, TRUE);
	CloseHandle(hFile);
	return 1;
}

VOID WINAPI FileIOCompletionRoutine(
	DWORD errorCode, 
	DWORD numOfBytesTransfered, 
	LPOVERLAPPED overlapped)
{
	_tprintf(_T("==========File write result==========\n"));
	_tprintf(_T("Error Code : %u\n"), errorCode);
	_tprintf(_T("transfered bytes len : %u\n"), numOfBytesTransfered);
	_tprintf(_T("The other info : %u\n"), (DWORD)overlapped->hEvent);
}