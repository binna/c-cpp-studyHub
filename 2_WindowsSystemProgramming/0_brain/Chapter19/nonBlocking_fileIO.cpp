#include <stdio.h>
#include <tchar.h>
#include <windows.h>

TCHAR strData1[] = _T("Test1\n");
TCHAR strData2[] = _T("Test2\n");
TCHAR strData3[] = _T("Test3\n");

VOID WINAPI FileIOCompletionRoutine(DWORD, DWORD, LPOVERLAPPED);

OVERLAPPED overlappedFilePtr;		// Default 0 ÃÊ±âÈ­!

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

	OVERLAPPED overlappedInstOne;
	memset(&overlappedInstOne, 0, sizeof(OVERLAPPED));
	overlappedInstOne.hEvent = (HANDLE)"First I/O";
	WriteFileEx(hFile, strData1, sizeof(strData1), &overlappedInstOne, FileIOCompletionRoutine);
	overlappedFilePtr.Offset += _tcslen(strData1) * sizeof(TCHAR);

	OVERLAPPED overlappedInstTwo;
	memset(&overlappedInstTwo, 0, sizeof(OVERLAPPED));
	overlappedInstTwo.Offset = overlappedFilePtr.Offset;
	overlappedInstTwo.hEvent = (HANDLE)"Second I/O";
	WriteFileEx(hFile, strData2, sizeof(strData2), &overlappedInstTwo, FileIOCompletionRoutine);
	overlappedFilePtr.Offset += _tcslen(strData2) * sizeof(TCHAR);

	OVERLAPPED overlappedInstThree;
	memset(&overlappedInstThree, 0, sizeof(OVERLAPPED));
	overlappedInstThree.Offset = overlappedFilePtr.Offset;
	overlappedInstThree.hEvent = (HANDLE)"First I/O";
	WriteFileEx(hFile, strData3, sizeof(strData3), &overlappedInstThree, FileIOCompletionRoutine);
	overlappedFilePtr.Offset += _tcslen(strData3) * sizeof(TCHAR);

	SleepEx(INFINITE, TRUE);
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