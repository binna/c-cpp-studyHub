#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <locale.h>
#include <tlHelp32.h>

#define STR_LEN			256
#define CMD_TOKEN_NUM	10

TCHAR ERROR_CMD[] = _T("'%s'실행할 수 있는 프로그램이 아닙니다.\n");

TCHAR cmdString[STR_LEN];
PTCHAR contex = NULL;
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

int cmdReadTokenize(void);
int CmdProcessing(int);
TCHAR* StrLower(TCHAR*);
void ListProcessInfo(void);
void KillProcess(void);

int _tmain(int argc, TCHAR* argv[])
{
	// 한글 입력을 가능하게 하기 위해
	_tsetlocale(LC_ALL, _T("Korean"));

	// 매개변수 전달인자가 있는 경우 처리를 위한 것이다
	// Start 명령어를 위한 처리
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
			_tcscpy_s(cmdTokenList[i - 1], STR_LEN - 1, argv[i]);
		CmdProcessing(argc - 1);
	}

	DWORD isExit = NULL;
	while (1)
	{
		int tokenNum = cmdReadTokenize();

		if (tokenNum == 0)		// Enter 입력 처리를 위한 부분
			continue;

		isExit = CmdProcessing(tokenNum);
		if (isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다."), stdout);
			break;
		}
	}
	return 0;
}

int cmdReadTokenize(void)
{
	TCHAR* token;

	_fputts(_T("Shine Command prompt>> "), stdout);
	_getts_s(cmdString);

	token = _tcstok_s(cmdString, seps, &contex);

	int tokenNum = 0;

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[tokenNum++], STR_LEN - 1, StrLower(token));

		// _tcstok_s 함수에서 첫 번째 매개변수로 NULL을 전달하면,
		// 이전에 처리했던 문자열의 다음 토큰을 추출한다
		token = _tcstok_s(NULL, seps, &contex);
	}

	return tokenNum;
}

int CmdProcessing(int tokenNum)
{
	BOOL isRun;
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	TCHAR cmdStringWithOptions[STR_LEN] = { 0, };
	TCHAR optString[STR_LEN] = { 0, };

	si.cb = sizeof(si);

	// _tcscmp(string1, string2)
	// < 0(음수)	string1이 string2보다	작은 경우
	// 0		string1이 string2와		같은 경우
	// > 0(양수)	string1이 string2보다	큰 경우
	if (!_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("start")))
	{
		if (tokenNum > 1)
		{
			for (int i = 1; i < tokenNum; i++)
			{
				_stprintf_s(optString, _T("%s %s"), optString, cmdTokenList[i]);
			}
			_stprintf_s(cmdStringWithOptions, _T("%s %s"), _T("cmd.exe"), optString);
		}
		else
		{
			_stprintf_s(optString, _T("%s"), _T("cmd.exe"));
		}

		isRun = CreateProcess(
			NULL, cmdStringWithOptions, NULL, NULL,
			TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("echo")))
	{
		// 입력된 문자열을 그대로 출력하는 echo 명령어
		for (int i = 1; i < tokenNum; i++)
		{
			_stprintf_s(optString, _T("%s %s"), optString, cmdTokenList[i]);
		}
		_tprintf(_T("echo message: %s\n"), optString);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("lp")))
	{
		ListProcessInfo();
	}
	else if (!_tcscmp(cmdTokenList[0], _T("kp")))
	{
		if (tokenNum < 2)
		{
			_tprintf(_T("usage: Kp <Process Name>\n"));
			return 0;
		}
		KillProcess();
	}
	else if (!_tcscmp(cmdTokenList[0], _T("sort")))
	{
		if (!_tcscmp(cmdTokenList[1], _T(">")))
		{
			// 상속 가능해야 지정 가능!

			SECURITY_ATTRIBUTES fileSec = { 0, };
			fileSec.nLength = sizeof(fileSec);
			fileSec.lpSecurityDescriptor = NULL;
			fileSec.bInheritHandle = TRUE;

			HANDLE hFile = CreateFile(
				cmdTokenList[2], 
				GENERIC_WRITE, 
				FILE_SHARE_READ, 
				&fileSec, 
				CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL, 
				NULL);

			si.hStdOutput = hFile;
			si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
			si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
			si.dwFlags |= STARTF_USESTDHANDLES;

			isRun = CreateProcess(
				NULL, 
				cmdTokenList[0], 
				NULL, 
				NULL, 
				TRUE, 
				0, 
				NULL, 
				NULL, 
				&si, 
				&pi);

			WaitForSingleObject(pi.hProcess, INFINITE);

			CloseHandle(hFile);
		}
		else
		{
			isRun = CreateProcess(
				NULL,
				cmdTokenList[0],
				NULL,
				NULL,
				FALSE,
				0,
				NULL,
				NULL,
				&si,
				&pi);
			
			WaitForSingleObject(pi.hProcess, INFINITE);
		}

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		_tcscpy_s(cmdStringWithOptions, STR_LEN - 1, cmdTokenList[0]);

		for (int i = 1; i < tokenNum; i++)
		{
			_stprintf_s(cmdStringWithOptions, _T("%s %s"), cmdStringWithOptions, cmdTokenList[i]);
		}

		isRun = CreateProcess(
			NULL, cmdStringWithOptions, NULL, NULL,
			TRUE, 0, NULL, NULL, &si, &pi);


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

/*
* List Process
*/
void ListProcessInfo(void)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("CreateToolhelp32Snapshot error!\n"));
		return;
	}

	// 프로세스 정보 얻기 위한 구조체 변수
	PROCESSENTRY32 pe32;

	// PROCESSENTRY32 변수는 사용하기 전에 정보 초기화 한다
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// 첫 번째 프로세스 정보 얻음
	if (!Process32First(hProcessSnap, &pe32))
	{
		_tprintf(_T("Process32First error!\n"));
		CloseHandle(hProcessSnap);
		return;
	}

	do
	{
		// 프로세스 이름, ID 정보 출력
		_tprintf(_T("%25s %d\n"), pe32.szExeFile, pe32.th32ProcessID);
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
}

/*
* Kill Process
*/
void KillProcess(void)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("CreateToolhelp32Snapshot(of process)"));
		return;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32))
	{
		_tprintf(_T("Process32First"));
		CloseHandle(hProcessSnap);
		return;
	}

	HANDLE hProcess;
	BOOL isKill = FALSE;
	do
	{
		// 입력된 프로세스 이름과 비교한다
		// 주의, 대소문자 구분 없이 비교 해야함
		// 왜? 모든 대문자를 소문자로 바꾸기 때문
		if (_tcsicmp(pe32.szExeFile, cmdTokenList[1]) == 0)
		{
			// 프로세스 ID를 핸들로 변환하는 과정
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

			if (hProcess != NULL)
			{
				// 프로세스를 강제 종료한다
				TerminateProcess(hProcess, -1);
				isKill = TRUE;
				CloseHandle(hProcess);
			}

			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	if (isKill == FALSE)
		_tprintf(_T("Kill process fail, Try again!\n"));
}