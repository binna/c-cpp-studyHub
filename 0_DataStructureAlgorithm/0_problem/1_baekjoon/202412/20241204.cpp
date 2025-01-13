// Problem 2563
// https://www.acmicpc.net/problem/2563
#include <iostream>
using namespace std;

int main(void)
{
	bool board[100][100] = { false, };

	int cnt, x, y, answer = 0;

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		cin >> x >> y;
		for (int i = x; i < x + 10; i++)
		{
			for (int j = y; j < y + 10; j++)
			{
				board[i][j] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (board[i][j])
			{
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}