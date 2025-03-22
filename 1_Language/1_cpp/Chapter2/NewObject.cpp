#include <iostream>
#include <cstdlib>
using namespace std;

class Simple
{
public:
	Simple()
	{
		cout << "I'm Simple constructor!" << endl;
	}
};

int main(void)
{
	Simple* sp1, * sp2;
	Simple sp3;
	cout << "case 1(" << sizeof(sp1) << "):";
	sp1 = new Simple;

	cout << endl << "=======================" << endl;
	cout << "case 2(" << sizeof(sp2) << "):";
	sp2 = (Simple*)malloc(sizeof(Simple) * 1);

	cout << endl << "=======================" << endl;
	cout << "case 3(" << sizeof(sp3) << "):";
	sp3 = Simple();

	cout << endl << "=======================" << endl;
	cout << sizeof(sp1) << "," << sizeof(sp2) << "," << sizeof(sp3) << endl;
	cout << "end of main" << endl;
	delete sp1;
	free(sp2);

	return 0;
}