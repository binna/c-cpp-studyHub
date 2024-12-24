#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <locale.h>

#define STR_LEN			256
#define CMD_TOKEN_NUM	10

TCHAR ERROR_CMD[] = _T("'%s'실행할 수 있는 프로그램이 아닙니다.\n");

int CmdPocessing(void);
TCHAR* StrLower(TCHAR*);

int _tmain(int argc, TCHAR* argv[])
{
	// 한글 입력을 가능하게 하기 위해
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1)
	{
		isExit = CmdPocessing();
		if (isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다."), stdout);
			break;
		}
	}
	return 0;
}

TCHAR cmdString[STR_LEN];
PTCHAR contex = NULL;
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

/*
* 명령어를 입력 받아서 해당 명령어에 지정되어 있는 기능을 수행한다
* exit가 입력되면 TRUE를 반환하고 이는 프로그램 종료로 이어진다
*/
int CmdPocessing(void)
{
	_fputts(_T("Shine Command prompt>> "), stdout);
	_getts_s(cmdString, STR_LEN - 1);

	TCHAR* token = _tcstok_s(cmdString, seps, &contex);
	int tokenNum = 0;

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[tokenNum++], STR_LEN - 1, StrLower(token));

		// _tcstok_s 함수에서 첫 번째 매개변수로 NULL을 전달하면,
		// 이전에 처리했던 문자열의 다음 토큰을 추출한다
		token = _tcstok_s(NULL, seps, &contex);
	}

	// _tcscmp(string1, string2)
	// < 0(음수)	string1이 string2보다	작은 경우
	// 0		string1이 string2와		같은 경우
	// > 0(양수)	string1이 string2보다	큰 경우
	if (!_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("추가 되는 명령어 1")))
	{
	}
	else if (!_tcscmp(cmdTokenList[0], _T("추가 되는 명령어 2")))
	{
	}
	else
	{
		STARTUPINFO si = { 0, };
		PROCESS_INFORMATION pi;

		BOOL isRun = CreateProcess(
			NULL, cmdTokenList[0], NULL, NULL, 
			TRUE, 0, NULL, NULL, &si, &pi);

		if (isRun == FALSE)
			_tprintf(ERROR_CMD, cmdTokenList[0]);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	return 0;
}

/*
* 문자열 내에 존재하는 모든 대문자를 소문자로 변경한다
* 변경된 문자열의 포인터를 반환한다
*/
TCHAR* StrLower(TCHAR* pStr)
{
	TCHAR* ret = pStr;

	while (*pStr)
	{
		if (_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}
	return ret;
}