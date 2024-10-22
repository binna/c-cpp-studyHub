// Problem 10807
// https://www.acmicpc.net/problem/10807
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int result = 0;

	int repeatNum;
	int checkNum;
	
	cin >> repeatNum;

	vector<int> v(repeatNum);

	for (int i = 0; i < repeatNum; i++)
	{
		int temp;
		cin >> temp;
		v[i] = temp;
	}

	cin >> checkNum;

	for (int i = 0; i < repeatNum; i++)
	{
		if (v[i] == checkNum)
			result += 1;
	}
	
	cout << result;

	return 0;
}