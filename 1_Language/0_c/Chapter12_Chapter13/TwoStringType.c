#include <stdio.h>

int main(void)
{
	char str1[] = "My String-1";	// 변수 형태의 문자열
	char* str2 = "My String-2";		// 상수 형태의 문자열
	printf("%s %s\n", str1, str2);

	str2 = "Our String";			// 가리키는 대상 변경
	printf("%s %s\n", str1, str2);

	str1[0] = 'x';					// 문자열 변경 성공
	//str2[0] = 'x';					// 문자열 변경 실패
	printf("%s %s\n", str1, str2);

	return 0;
}