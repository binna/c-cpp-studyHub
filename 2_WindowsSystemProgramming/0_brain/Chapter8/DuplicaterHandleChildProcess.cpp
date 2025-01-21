#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hParent = (HANDLE)_ttoi(argv[1]);
	DWORD isSucess = WaitForSingleObject(hParent, INFINITE);

	_tprintf(_T("[Child Process]\n"));

	if (isSucess == WAIT_FAILED)
	{
		_tprintf(_T("WAIT_FAILED returned!\n"));
		Sleep(10000);
		return -1;
	}
	else
	{
		_tprintf(_T("General Lee said, \"Don't inform\n"));
		_tprintf(_T("the enemy my death\"\n"));
		Sleep(10000);
		return 0;
	}
}