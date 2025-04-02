#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjectCnt;

	SoSimple()
	{
		simObjectCnt++;
	}
};

int SoSimple::simObjectCnt;

int main(void)
{
	cout << SoSimple::simObjectCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << endl << endl << SoSimple::simObjectCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	cout << sim1.simObjectCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	cout << sim2.simObjectCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
}