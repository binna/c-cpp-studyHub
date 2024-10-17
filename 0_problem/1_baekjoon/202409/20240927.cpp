// Problem 1000
// https://www.acmicpc.net/submit/1000

#include <iostream>
using namespace std;

int solution(int num1, int num2)
{
	int result = num1 + num2;
	return result;
}

int main(void)
{
	int input1, input2;

	cin >> input1;
	cin >> input2;

	cout << solution(input1, input2) << endl;

	return 0;
}