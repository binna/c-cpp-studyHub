#include <iostream>
using namespace std;

// return int&
// 호출자가 리턴값을 어떻게 받느냐에 따라
// 값도 가능하고 참조값도 가능하고
int& RefFuncOne(int& ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefFuncOne(num1);
	int& num3 = RefFuncOne(num1);

	num1++;
	num2 += 100;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl << endl << endl;

	return 0;
}