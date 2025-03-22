#include <iostream>
using namespace std;

// return int
// 무조건 값만 가능
int RefRetFuncTwo(int& ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncTwo(num1);
	//int& num3 = RefRetFuncTwo(num1);		// 오류

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl << endl << endl;

	return 0;
}