// Problem 1546
// https://www.acmicpc.net/problem/1546
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int num;

	double max{}, tatalNum = 0;

	cin >> num;

	vector<int> v(num);

	for (int i = 0; i < num; i++)
	{
		cin >> v[i];
		
		if (i == 0)
			max = v[i];
		else if (max < v[i])
			max = v[i];
	}

	for (int i = 0; i < num; i++)
	{
		tatalNum += (v[i] / max * 100);
	}

	cout << tatalNum / num;

	return 0;
}