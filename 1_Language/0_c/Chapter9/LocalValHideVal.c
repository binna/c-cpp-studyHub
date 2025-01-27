#include <stdio.h>

int main(void)
{
	int num = 1;

	if (num == 1)
	{
		int num = 7;		// 이 행을 주석 처리와 주석 처리 안 한 상태 각각 실행 결과 확인하기
		num += 10;
		printf("if문 내 지역변수 num: %d\n", num);
	}
	printf("main 함수 내 지역변수 num: %d\n", num);
	return 0;
}