#include <stdio.h>

#define STRING_JOB(A, B)	 #A"의 직업은 " B"입니다."

int main(void)
{
	printf("%s\n", STRING_JOB("shine", "서버 개발자"));
	printf("%s\n", STRING_JOB('S', "서버 개발자"));
	printf("%s\n", STRING_JOB(94, "서버 개발자"));

	return 0;
}