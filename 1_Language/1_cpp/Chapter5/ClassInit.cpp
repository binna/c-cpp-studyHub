#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		:num1(n1), num2(n2)
	{
		cout << "SoSimple(int n1, int n2)" << endl;
	}
	SoSimple(SoSimple& copy)
		:num1(copy.num1), num2(copy.num2)
	{
		cout << "Colled SoSimple(SoSimple& copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};
int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전 " << sizeof(sim1) << endl;

	SoSimple sim2 = sim1;		// SoSimple(sim1); 으로 변환
	cout << "생성 및 초기화 직후 " << sizeof(sim2) << endl;
	sim1.ShowSimpleData();

	return 0;
}