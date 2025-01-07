#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot;
	TCHAR message[50];
	TCHAR inputMsg[40];
	TCHAR nickname[10];
	DWORD bytesWritten;			// number of bytes write

	hMailSlot = CreateFile(
		SLOT_NAME,
		GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hMailSlot == INVALID_HANDLE_VALUE)
	{
		_fputts(_T("Unalbe to create mailslot!\n"), stdout);
		return 1;
	}

	_fputts(_T("nickname: "), stdout);
	_tscanf_s(_T("%s"), nickname, _countof(nickname));
	nickname[_countof(nickname) - 1] = 0;

	while (getchar() != '\n');	// 입력 버퍼 제거
	
	while (1)
	{
		_tprintf(_T("%s>"), nickname);

		_tcscpy_s(message, _countof(nickname), nickname);
		_tcscat_s(message, _countof(message), _T(">"));

		_fgetts(inputMsg, sizeof(inputMsg) / sizeof(TCHAR), stdin);

		_tcscat_s(message, _countof(message), inputMsg);

		if (!WriteFile(hMailSlot, message, _tcslen(message) * sizeof(TCHAR), &bytesWritten, NULL))
		{
			_fputts(_T("Unable to write!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcscmp(message, _T("exit")))
		{
			_fputts(_T("Good Bye!"), stdout);
			break;
		}
	}

	CloseHandle(hMailSlot);
	
	return 0;
}