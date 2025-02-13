#include <stdio.h>
#include <tchar.h>
#include <windows.h>



int _tmain(int argc, TCHAR* argv[])
{
	TCHAR string[] = 
		_T("Hey, get a life!")
		_T("you don't even have two pennies to rub together.");

	TCHAR seps[] = _T(" ,.!");
	PTCHAR nextToken;

	// 토큰 분리 조건, 문자열 설정 및 첫 번째 토근 반환
	TCHAR* token = _tcstok_s(string, seps, &nextToken);

	// 계속해서 토큰을 반환 및 출력
	while (token != NULL)
	{
		_tprintf(_T(" %s\n"), token);
		token = _tcstok_s(NULL, seps, &nextToken);
	}

	return 0;
}