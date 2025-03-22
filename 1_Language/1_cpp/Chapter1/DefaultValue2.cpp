#include <iostream>
using namespace std;

int Adder(int num1 = 1, int num2 = 2);

int main(void)
{
	cout << Adder();
	cout << Adder(5);
	cout << Adder(3, 5);
	return 0;
}

int Adder(int num1, int num2)
{
	return num1 + num2;
}