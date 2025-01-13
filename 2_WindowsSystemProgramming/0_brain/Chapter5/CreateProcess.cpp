#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>

#define DIR_LEN		MAX_PATH + 1

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	si.dwFillAttribute = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;

	LPCWSTR title = _T("I am a boy!");
	si.lpTitle = new TCHAR[_tcslen(title) + 1];
	_tcscpy_s(si.lpTitle, _tcslen(title) + 1, title);

	TCHAR command[] = _T("AdderProcess.exe 10 20");
	TCHAR cDir[DIR_LEN];
	BOOL state;

	GetCurrentDirectory(DIR_LEN, cDir);		// 현재 디렉터리 확인
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	SetCurrentDirectory(_T("exe"));			// 상대 경로로 설정함
											// AdderProcess.exe는 만든 exe 폴더 안에 있음

	GetCurrentDirectory(DIR_LEN, cDir);		// 현재 디렉터리 확인
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);
	
	state = CreateProcess(					// 프로세스 생성
		NULL,								// 실행파일의 이름
		command,							// main 함수에 전달될 문자열
		NULL, NULL, TRUE, 
		CREATE_NEW_CONSOLE, 
		NULL, NULL, 
		&si, &pi);

	if (state != 0)
		_fputts(_T("Creation OK!\n"), stdout);
	else
		_fputts(_T("Creation Error!\n"), stdout);

	return 0;
}