#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjectCnt;
public:
	SoSimple()
	{
		simObjectCnt++;
		cout << simObjectCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoSimplex
{
private:
	static int cmxObjectCnt;
public:
	SoSimplex()
	{
		cmxObjectCnt++;
		cout << cmxObjectCnt << "번째 SoSmplex 객체 - 생성자" << endl;
	}

	SoSimplex(const SoSimplex& copy)
	{
		cmxObjectCnt++;
		cout << cmxObjectCnt << "번째 SoSimplex 객체 - 복사 생성자" << endl;
	}
};

int SoSimple::simObjectCnt;
int SoSimplex::cmxObjectCnt;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoSimplex cmx1;
	SoSimplex cmx2 = cmx1;
	SoSimplex();

	cout << &cmx2 << endl;

	return 0;
}