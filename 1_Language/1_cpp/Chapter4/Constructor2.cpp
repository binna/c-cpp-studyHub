#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
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
	// 1. 매개변수 없는 생성자 호출
	SimpleClass sc1;
	SimpleClass sc2{};

	sc1.ShowData();
	sc2.ShowData();

	// 2. 매개변수 있는 생성자 호출
	SimpleClass sc3(30);
	SimpleClass sc4{10, 20};

	sc3.ShowData();
	sc4.ShowData();

	// 책 예제
	// 보통 함수의 원형은 전역적으로(함수 밖에) 선언하지만,
	// 아래의 예제처럼 함수 내에 지역적으로 선언 가능
	SimpleClass sc5();			// 함수의 원형 선언
	SimpleClass mysc = sc5();
	mysc.ShowData();
	return 0;
}

SimpleClass sc5()
{
	SimpleClass sc(20, 30);
	return sc;
}