#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass()
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}

	//SimpleClass(int n1 = 0, int n2 = 0)
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();

	cout << sizeof(sc1) << endl;

	SimpleClass* sc4 = new SimpleClass();

	cout << sizeof(sc4) << endl;


	SimpleClass* sc5 = new SimpleClass[10];

	cout << sizeof(sc5) << endl;

	SimpleClass sc6[10] = {
		SimpleClass(1, 2), SimpleClass(3, 4),
		SimpleClass(1, 2), SimpleClass(3, 4),
		SimpleClass(1, 2), SimpleClass(3, 4),
		SimpleClass(1, 2), SimpleClass(3, 4),
		SimpleClass(1, 2), SimpleClass(3, 4)
	};

	cout << sizeof(sc6) << endl;

	return 0;
}