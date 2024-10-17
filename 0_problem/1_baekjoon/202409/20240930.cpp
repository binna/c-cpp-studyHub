// Problem 1001
// https://www.acmicpc.net/problem/1001
//#include <iostream>
//using namespace std;
//
//int Minus(int num1, int num2)
//{
//	return num1 - num2;
//}
//
//int main(void)
//{
//	int input1, input2;
//
//	cin >> input1;
//	cin >> input2;
//
//	cout << Minus(input1, input2);
//	
//	return 0;
//}

// Problem 10998
// https://www.acmicpc.net/problem/10998
//#include <iostream>
//using namespace std;
//
//int Multiplication(int num1, int num2)
//{
//	return num1 * num2;
//}
//
//int main(void)
//{
//	int input1, input2;
//
//	cin >> input1;
//	cin >> input2;
//
//	cout << Multiplication(input1, input2);
//	return 0;
//}

// Problem 1008
// https://www.acmicpc.net/problem/1008
#include <iostream>
using namespace std;

double Division(double num1, double num2)
{
	return num1 / num2;
}

int main(void)
{
	int input1, input2;

	cin >> input1;
	cin >> input2;

	cout.precision(9);			// 실수를 n자리 만큼만 출력하게 한다.
	cout << fixed;				// 고정 소수점 표기로 fixed를 사용한 이후부터는 cout.precision(n)에서 받은 n값 만큼 소수점 아래 자리수를 출력

	cout << Division(input1, input2);

	cout.unsetf(ios::fixed);	// fixed를 해제

	return 0;
}