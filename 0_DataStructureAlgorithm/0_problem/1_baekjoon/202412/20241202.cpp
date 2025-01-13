// Problem 10798
// https://www.acmicpc.net/problem/10798
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	string temp;
	int size;
	int max = -1;

	vector<queue<char>> v;
		
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		size = temp.length();
		if (size > max) 
			max = size;
		queue<char> queue;
		for (int j = 0; j < size; j++)
		{
			queue.push(temp[j]);
		}
		v.push_back(queue);
	}

	while (true)
	{
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (v[i].empty() == 0)
			{
				cout << v[i].front();
				v[i].pop();
			}
			else
				cnt += 1;
		}

		if (cnt >= 5)
			break;
	}

	return 0;
}