#include <stdio.h>

int main(void)
{
	char ch;
	printf("아스키 문자 입력: ");
	scanf_s("%c", &ch, sizeof(char));
	printf("아스키 코드 값: %d\n", ch);
	return 0;
}