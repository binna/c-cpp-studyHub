#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}

	Person()
	{
		name = nullptr;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << ", ";
		cout << "나이 : " << age << endl;
	}

	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person* parr[3];
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;

		cout << "나이 : ";
		cin >> age;

		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	cout << sizeof(parr) << endl;

	Person* p;

	cout << "이름 : ";
	cin >> namestr;

	cout << "나이 : ";
	cin >> age;

	p = new Person(namestr, age);

	p->ShowPersonInfo();

	cout << sizeof(p) << endl;

	return 0;
}