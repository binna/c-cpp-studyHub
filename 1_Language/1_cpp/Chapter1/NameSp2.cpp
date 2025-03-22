#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc(void);
}

namespace ProgComImpl
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
}


void BestComImpl::SimpleFunc(void)
{
	cout << "BestComImpl이 정의한 함수" << endl;
}

void ProgComImpl::SimpleFunc(void)
{
	cout << "ProgComImpl이 정의한 함수" << endl;
}