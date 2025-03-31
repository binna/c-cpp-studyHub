#include <iostream>
#include "Car.h"
using namespace std;

int main(void)
{
	Car run99;
	run99.InitMembers((char*)"run99", 100);
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	cout << sizeof(run99) << endl;

	Car run77;
	run77.InitMembers((char*)"run77", 100);
	run77.Accel();
	run77.Break();
	run77.ShowCarState();

	return 0;
}