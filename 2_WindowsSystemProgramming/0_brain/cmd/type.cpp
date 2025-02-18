#include <stdio.h>
#include <stdio.h>
#include <tchar.h>

int TYPE(TCHAR* filename)
{
	TCHAR StringBuff[1024];

	FILE* filePtr;
	_tfopen_s(&filePtr, filename, _T("rt"));

	if (filePtr == NULL)
	{
		_tprintf(_T("file error"));
		return -1;
	}

	while (_fgetts(StringBuff, 1024, filePtr))
		_fputts(StringBuff, stdout);

	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	if (argc < 2)
		return -1;

	if (TYPE(argv[1]) != 0)
		return -2;

	return 0;
}