#include <iostream>
using namespace std;

int BoxValue(int length, int width = 1, int height = 1);

int main(void)
{
	cout << "[3, 3, 3] : " << BoxValue(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxValue(5, 5) << endl;
	cout << "[7, D, D] : " << BoxValue(7) << endl;
}

int BoxValue(int length, int width, int height)
{
	return length * width * height;
}