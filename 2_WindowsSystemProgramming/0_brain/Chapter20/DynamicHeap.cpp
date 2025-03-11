#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define TEXT_LENG		30

int _tmain(int argc, TCHAR* argv[])
{
	SYSTEM_INFO sysInfo;

	GetSystemInfo(&sysInfo);
	UINT pageSize = sysInfo.dwPageSize;

	// 1. 힙 생성
	HANDLE hHeap = HeapCreate(HEAP_NO_SERIALIZE, pageSize * 10, pageSize * 100);

	if (hHeap == NULL)
		return -1;

	// 2. 메모리 할당
	int* p = (int*)HeapAlloc(hHeap, 0, sizeof(int) * 10);

	if (p == 0)
		return -1;

	// 3. 메모리 활용
	for (int i = 0; i < 10; i++)
		p[i] = i;

	// 4. 메모리 해제
	HeapFree(hHeap, 0, p);

	HANDLE hDefaultHeap = GetProcessHeap();
	TCHAR* pDefault = (TCHAR*)HeapAlloc(hDefaultHeap, HEAP_NO_SERIALIZE, sizeof(TCHAR) * TEXT_LENG);

	if (pDefault == NULL)
		return -1;

	// _tcscpy_s() 호출 시 크기를 배열 개수를 받아야 함
	_tcscpy_s(pDefault, TEXT_LENG, _T("Default Heap!"));
	_tprintf(_T("%s\n"), pDefault);
	HeapFree(hDefaultHeap, HEAP_NO_SERIALIZE, pDefault);
	return 1;
}