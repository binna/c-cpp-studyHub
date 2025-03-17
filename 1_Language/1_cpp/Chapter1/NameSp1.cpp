#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc(void)
	{
		cout << "BestComImpl이 정의한 함수" << endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc(void)
	{
		cout << "ProgComImpl이 정의한 함수" << endl;
	}
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
}