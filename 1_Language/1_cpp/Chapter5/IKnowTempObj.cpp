#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj : " << this << endl;
	}
	~Temporary()
	{
		cout << "destroy obj" << this << endl;
	}
	void ShowTempInfo()
	{
		cout << "My address is " << this << endl;
	}
};

int main(void)
{
	Temporary(100);
	cout << sizeof(Temporary(100)) << endl;
	cout << "================================" << endl << endl;

	Temporary(100).ShowTempInfo();
	cout << "================================" << endl << endl;

	const Temporary& ref = Temporary(100);
	cout << sizeof(ref) << " end main" << endl << endl;

	return 0;
}