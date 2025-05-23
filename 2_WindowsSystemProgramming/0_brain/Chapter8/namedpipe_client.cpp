#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define BUF_SIZE		1024

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hPipe;
	TCHAR readDataBuf[BUF_SIZE + 1] = { 0 };
	LPCWSTR pipeName = _T("\\\\.\\pipe\\simple_pipe");


	// 1. 파이프 열기
	while (1)
	{
		hPipe = CreateFile(
			pipeName,						// 연결할 파이프 이름
			GENERIC_READ | GENERIC_WRITE,	// 읽기, 쓰기 모드 동시 설정
			0, 
			NULL, 
			OPEN_EXISTING, 
			0, 
			NULL);

		if (hPipe != INVALID_HANDLE_VALUE)
			break;

		if (GetLastError() != ERROR_PIPE_BUSY)
		{
			_tprintf(_T("Could not open pipe\n"));
			return 0;
		}

		if (!WaitNamedPipe(pipeName, 20000))
		{
			_tprintf(_T("Could not open pipe\n"));
			return 0;
		}
	}

	// 2. 파이프 모드 설정
	DWORD pipeMode = PIPE_READMODE_MESSAGE | PIPE_WAIT;		// 메시지 기반으로 모드 변경
	BOOL isSuccess = SetNamedPipeHandleState(
		hPipe,			// 서버 파이프와 연결된 핸들
		&pipeMode,		// 변경할 모드 정보
		NULL,
		NULL);
	
	if (!isSuccess)
	{
		_tprintf(_T("SetNamedPipeHandleState failed\n"));
		return 0;
	}
	
	// 3. 서버로 파일 이름 전송
	LPCWSTR fileName = _T("news.txt");
	DWORD bytesWritten = 0;

	isSuccess = WriteFile(
		hPipe,									// 서버 파이프와 연결될 핸들
		fileName,								// 전송할 메시지
		(_tcslen(fileName) + 1) * sizeof(TCHAR),// 메시지 길이
		&bytesWritten,							// 전송된 바이트 수
		NULL);

	if (!isSuccess)
	{
		_tprintf(_T("WriteFile failed\n"));
		return 0;
	}

	// 4. 서버가 전송한 데이터를 클라이언트가 읽기
	DWORD bytesRead = 0;
	while (1)
	{
		isSuccess = ReadFile(
			hPipe,						// 서버 파이프와 연결된 핸들
			readDataBuf,				// 데이터 수신할 버퍼
			BUF_SIZE * sizeof(TCHAR),	// 버퍼 사이즈
			&bytesRead,					// 수신한 바이트 수
			NULL);

		if (!isSuccess && GetLastError() != ERROR_MORE_DATA)
			break;

		// bytesRead / sizeof(TCHAR)를 사용하는 이유는 
		// bytesRead가 바이트 단위로 반환되기 때문
		readDataBuf[bytesRead / sizeof(TCHAR)] = 0;

		_tprintf(_T("%s %d\n"), readDataBuf, bytesRead);
	} 

	CloseHandle(hPipe);
	return 0;
}