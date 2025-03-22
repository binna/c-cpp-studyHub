#include <iostream>
using namespace std;

inline int SQURE(int x)
{
	return x * x;
}

int main(void)
{
	cout << SQURE(5) << endl;
	cout << SQURE(12) << endl;
	return 0;
}