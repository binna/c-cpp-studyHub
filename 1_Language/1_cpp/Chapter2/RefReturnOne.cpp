#include <iostream>
using namespace std;

int& RefFuncOne_1(int& ref)
{
	ref++;
	return ref;
}

int RefFuncOne_2(int& ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int& num2 = RefFuncOne_1(num1);

	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl << endl << endl;

	num1 = 1;
	num2 = RefFuncOne_2(num1);
	
	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl << endl << endl;

	int num3 = RefFuncOne_2(num1);

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	cout << "num3: " << num3 << endl << endl << endl;

	num1++;
	num2++;
	num3++;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	cout << "num3: " << num3 << endl << endl << endl;

	return 0;
}