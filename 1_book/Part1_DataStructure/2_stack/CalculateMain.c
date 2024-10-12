#include "0_Calculate_My.h"

// 이론이 이해가 안되서 참고했던 블로그
// https://www.crocus.co.kr/1703

// Key Point
// 1. 피연산자가 들어오면 바로 출력한다
// 2. 연산자가 들어오면 우선순위가 높거나 같은 것들은 빼서 출력하고 자신의 스택에 담는다
// 3. 여는 괄호를 만나면 스택에 담는다
// 4. 닫는 괄호를 만나면 여는 괄호를 만날 때까지 출력한다

// 내 코드에 한계
// 1. 숫자가 0 ~ 9까지만 가능함

int main(void)
{
	//ConvertPostfix0("3+(5+3/2)+7");
	ConvertPostfix0("3+7+8");
	ConvertPostfix0("3+7+9-8");
	ConvertPostfix0("3+7/9-8");
	ConvertPostfix0("3+4+7/9-8");
	printf("결과 : %s\n", ConvertPostfix0("3+(5+3*2)+7"));

	printf("\n\n");

	double resultNum = Calculate0("132*-");
	printf("result : %lf\n", resultNum);

	resultNum = Calculate0("3532*++7+");
	printf("result : %lf\n", resultNum);

	return 0;
}