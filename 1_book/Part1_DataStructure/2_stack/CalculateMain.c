//#include "0_Calculate_My.h"
//
//// 이론이 이해가 안되서 참고했던 블로그
//// https://www.crocus.co.kr/1703
//
//// Key Point
//// 1. 피연산자가 들어오면 바로 출력한다
//// 2. 연산자가 들어오면 우선순위가 높거나 같은 것들은 빼서 출력하고 자신의 스택에 담는다
//// 3. 여는 괄호를 만나면 스택에 담는다
//// 4. 닫는 괄호를 만나면 여는 괄호를 만날 때까지 출력한다
//
//// 내 코드에 한계
//// 1. 숫자가 0 ~ 9까지만 가능함
//
//int main(void)
//{
//	ConvertPostfix0("3+(5+3/2)+7");
//	ConvertPostfix0("3+(5+3*2)+7");
//	ConvertPostfix0("3+7+8");
//	ConvertPostfix0("3+7+9-8");
//	ConvertPostfix0("3+7/9-8");
//	ConvertPostfix0("3+4+7/9-8");
//	ConvertPostfix0("3+6/7");
//	printf("결과 : %s\n", ConvertPostfix0("3+(5+3*2)+7"));
//
//	printf("\n\n");
//
//	double resultNum = Calculate0("132*-");
//	printf("result : %lf\n", resultNum);
//
//	resultNum = Calculate0("3532*++7+");
//	printf("result : %lf\n", resultNum);
//
//	resultNum = Calculate0(ConvertPostfix0("3+(5+3*2)+7"));
//	printf("result : %lf\n", resultNum);
//
//	return 0;
//}

//#include "1_Calculate_book.h"
//
//int main(void)
//{
//	char InfixExpression[100];
//	char PostfixExpression[100];
//
//	double result = 0.0;
//
//	memset(InfixExpression, 0, sizeof(InfixExpression));
//	memset(PostfixExpression, 0, sizeof(PostfixExpression));
//
//	printf("Enter Infix Expression: ");
//	scanf_s("%s", InfixExpression, sizeof(InfixExpression));
//	
//
//	GetPostfix(InfixExpression, PostfixExpression);
//
//	printf("Infix: %s\nPostfix: %s\n\n", InfixExpression, PostfixExpression);
//
//	result = Calculate(PostfixExpression);
//
//	printf("Calculate Result : %lf\n", result);
//
//	return 0;
//}

#include "2_Calculate_Final.h"

int main(void)
{
	char InfixExpression[100] = "1+3.334/(4.38*(110-7729))";
	char PostfixExpression[100];

	double result = 0.0;

	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	GetPostfix2(InfixExpression, PostfixExpression);

	printf("Infix: %s\nPostfix: %s\n\n", InfixExpression, PostfixExpression);

	result = Calculate2(InfixExpression, 0);

	printf("Calculate Result : %lf\n", result);
	printf("\n\n");

	result = Calculate2(PostfixExpression, 1);

	printf("Calculate Result : %lf\n", result);

	return 0;
}