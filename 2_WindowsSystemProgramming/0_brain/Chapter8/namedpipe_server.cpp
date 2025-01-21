#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define BUF_SIZE		1024

int CommToClient(HANDLE);

int _tmain(int argc, TCHAR* argv[])
{
	LPCWSTR pipeName = _T("\\\\.\\pipe\\simple_pipe");
	HANDLE hPipe;

	while (1)
	{
		// 1. 파이프 생성
		hPipe = CreateNamedPipe(
			pipeName,					// 파이브 이름
			PIPE_ACCESS_DUPLEX,			// 읽기, 쓰기 모드 지정
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 
			PIPE_UNLIMITED_INSTANCES,	// 최대 파이프 개수
			BUF_SIZE,					// 출력 버퍼 사이즈
			BUF_SIZE,					// 입력 버퍼 사이즈
			20000,						// 클라이언트 타임 아웃
			NULL);						// 디폴트 보안 속성

		if (hPipe == INVALID_HANDLE_VALUE)
		{
			_tprintf(_T("CreatePipe failed"));
			return -1;
		}

		// 2. 클라이언트 연결 대기
		BOOL isSuceess = 0;
		isSuceess = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

		if (isSuceess)
		{
			// 3-1. 클라이언트와 통신 시작
			CommToClient(hPipe);
		}
		else
		{
			// 3-2. 연결 실패 시 파이프 핸들 닫기
			CloseHandle(hPipe);
		}
	}

	return 1;
}

// 클라이언트와의 통신을 처리하는 함수
int CommToClient(HANDLE hPipe)
{
	TCHAR fileName[MAX_PATH + 1] = { 0 };
	TCHAR dataBuf[BUF_SIZE + 1];

	BOOL isSuccess;
	DWORD fileNameSize;

	// (1) 클라이언트로부터 파일 이름 수신
	isSuccess = ReadFile(
		hPipe,						// 파이프 핸들
		fileName,					// 읽을 데이터를 수신하는 버퍼에 대한 포인터 -> read 버퍼 지정
		MAX_PATH * sizeof(TCHAR),	// 읽을 수 있는 최대 바이트 수 -> read 버퍼 사이즈
		&fileNameSize,				// 읽은 바이트 수를 받는 변수에 대한 포인터 -> 수신한 데이터 크기
		NULL
	);

	if (!isSuccess || fileNameSize == 0)
	{
		_tprintf(_T("Pipe read message error!\n"));
		return -1;
	}

	// 문자열의 끝에 널 종료 추가
	fileName[fileNameSize / sizeof(TCHAR)] = 0;


	// (2) 클라이언트로부터 받은 파일 이름으로 파일 열기
	FILE* filePtr;

	errno_t errorNo = _tfopen_s(&filePtr, fileName, _T("r"));

	if (errorNo != 0 || filePtr == NULL)
	{
		_tprintf(_T("File open fault!/errorNo : %d/%s\n"), errorNo, fileName);
		return -1;
	}


	DWORD bytesWritten = 0;
	DWORD bytesRead = 0;
	int fileSize;
	size_t bytesToRead;

	// 파일 크기 계산
	fseek(filePtr, 0, SEEK_END);
	fileSize = ftell(filePtr);
	rewind(filePtr);	// 파일 포인터를 다시 시작 위치로 이동
	
	// (3) 파일 내용을 읽어 클라이언트로 전송
	while (fileSize > 0)
	{
		bytesToRead = (fileSize < BUF_SIZE) ? fileSize : BUF_SIZE;

		bytesRead = fread(dataBuf, 1, bytesToRead, filePtr);

		if (bytesRead > 0)
		{
			dataBuf[bytesRead / sizeof(TCHAR)] = 0;

			_tprintf(_T("Sending to client: %s\n"), dataBuf);

			WriteFile(
				hPipe,
				dataBuf,
				bytesRead,
				&bytesWritten,
				NULL);

			if (bytesRead != bytesWritten)
			{
				_tprintf(_T("Pipe write message error!\n"));
				break;
			}

			fileSize -= bytesRead;
		}
		else
		{
			_tprintf(_T("Failed to read file!\n"));
			break;
		}
	}

	FlushFileBuffers(hPipe);
	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);
	return 1;
}