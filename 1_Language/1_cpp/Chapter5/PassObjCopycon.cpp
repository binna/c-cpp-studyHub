#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2) { /* empty */ }
	SoSimple(const SoSimple& copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	void ShowData()
	{
		cout << "num : " << endl;
	}
};

void SimpleFuncObj(SoSimple ob)
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7, 3);
	cout << "함수 호출 전" << endl;

	SimpleFuncObj(obj);
	cout << "함수 호출 후" << endl;

	return 0;
}