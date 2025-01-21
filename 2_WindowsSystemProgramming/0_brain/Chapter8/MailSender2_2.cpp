#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot;
	TCHAR message[50];
	DWORD bytesWritten;

	// 핸들을 얻는 코드 //////////////////////////////////////
	FILE* file;
	errno_t err = _tfopen_s(&file, _T("InheritableHandle.txt"), _T("rt"));
	if (err != 0 || file == NULL) {
		_tprintf(_T("파일을 열 수 없습니다.\n"));
		return 2;
	}

	_ftscanf_s(file, _T("%d"), &hMailSlot);
	fclose(file);
	_tprintf(_T("Inheritable Handle : %d\n"), (int)hMailSlot);
	////////////////////////////////////////////////////////

	while (1)
	{
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

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