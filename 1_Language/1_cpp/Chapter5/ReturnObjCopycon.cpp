#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2 = 16;
public:
	SoSimple(int n1) : num1(n1) { /*empty*/ }
	SoSimple(const SoSimple& copy) : num1(copy.num1)
	{
		cout << "SoSimple(const SoSimple& copy)" << endl;
	}
	SoSimple& AddNum(int n)
	{
		num1 += n;
		return *this;
	}
	void ShowData()
	{
		cout << "num : " << num1 << endl;
	}
};

SoSimple SimpleFunObj(SoSimple ob)
{
	cout << "return ÀÌÀü" << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFunObj(obj).AddNum(30).ShowData();

	printf("==================================\n");

	obj.ShowData();
	return 0;
}