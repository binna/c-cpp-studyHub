#include <stdio.h>

void SoSimpleFunc(void)
{
	printf("I am so Simple\n");
}

int main(void)
{
	int num = 20;
	void* ptr;

	ptr = &num;			// 변수 num의 주소값 저장
	printf("%p\n", ptr);

	ptr = SoSimpleFunc;	// 함수 SoSimpleFunc의 주소값 저장
	printf("%p\n", ptr);

	return 0;
}