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

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}

	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1((char*)"Lee", 29);
	Person man2((char*)"Jang", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	cout << sizeof(man1) << "," << sizeof(man2) << endl;
	return 0;
}