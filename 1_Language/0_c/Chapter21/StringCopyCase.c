#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	strcpy_s(str2, sizeof(str2), str1);
	puts(str2);

	//errno_t strncpy_s(
	// char* strDest, size_t numberOfElements, 
	// const char* strSource, size_t count);
	//   strDest : 대상 문자열
	//   numberOfElements : 대상 문자열의 크기(문자)
	//   strSource : 소스 문자열
	//   count : 복사할 문자 수
	//           복사할 문자수를 기입할 때, NULL 공간 필요
	strncpy_s(str3, sizeof(str3), str1, sizeof(str3) - 1);
	puts(str3);
	
	return 0;
}