#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#define MAX_PAGE				10		// 할당할 최대 페이지 개수

int* nextPageAddr;
DWORD pageCnt = 0;
DWORD pageSize;

int PageFaultExceptionFilter(DWORD);

int _tmain(int argc, TCHAR* argv[])
{
	LPVOID baseAddr;
	int* lpPtr;
	SYSTEM_INFO sSysInfo;

	GetSystemInfo(&sSysInfo);
	pageSize = sSysInfo.dwPageSize;		// 페이지 사이즈 획득

	// MAX_PAGE의 개수만큼 페이지 RESERVE
	baseAddr = VirtualAlloc(
		NULL,							// 임의 주소 할당
		MAX_PAGE * pageSize,			// 예약 메모리 크기
		MEM_RESERVE,					// reserve
		PAGE_READWRITE);					// no Access
	
	if (baseAddr == NULL)
	{
		_tprintf(_T("VirtualAlloc reserve failed"));
	}

	lpPtr = (int*)baseAddr;		// 배열의 시작 번지와 같은 의미 부여
	nextPageAddr = (int*)baseAddr;

	// page fault 발생 시 예외 발생
	for (DWORD i = 0; i < (MAX_PAGE * pageSize) / sizeof(DWORD); i++)
	{
		__try
		{
			lpPtr[i] = i;
		}
		__except (PageFaultExceptionFilter(GetExceptionCode()))
		{
			ExitProcess(GetLastError());		// 예외처리 문제 발생 시 종료
		}
	}

	BOOL isSuccess = VirtualFree(baseAddr, 0, MEM_RESERVE);

	if (isSuccess)
		_tprintf(_T("Release successed!"));
	else
		_tprintf(_T("Release failed!"));
}



int PageFaultExceptionFilter(DWORD exptCode)
{
	if (exptCode != EXCEPTION_ACCESS_VIOLATION)
	{
		_tprintf(_T("Exception code = %d\n"), exptCode);
		return EXCEPTION_EXECUTE_HANDLER;
	}

	_tprintf(_T("Excption is a page fault\n"));

	if (pageCnt >= MAX_PAGE)
	{
		_tprintf(_T("Excption: out of pages\n"));
		return EXCEPTION_EXECUTE_HANDLER;
	}

	LPVOID lpvResult = VirtualAlloc(
		(LPVOID)nextPageAddr,
		pageSize,
		MEM_COMMIT,
		PAGE_READWRITE);

	if (lpvResult == NULL)
	{
		_tprintf(_T("VirtualAlloc failed\n"));
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else
	{
		_tprintf(_T("Allocating another page.\n"));
	}

	pageCnt++;
	nextPageAddr += pageSize / sizeof(int);
	return EXCEPTION_CONTINUE_EXECUTION;
}