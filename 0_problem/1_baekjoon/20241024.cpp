// Problem 2566
// https://www.acmicpc.net/problem/2566
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
	int board[9][9] = { 0, };
	
	for (int i = 0; i < 9; i++)
	{
		string input;
		getline(cin, input);

		stringstream ss(input);
		int j = 0;
		while (ss >> input)
		{
			int temp = stoi(input);
			board[i][j] = temp;
			j++;
		}
	}


	int max = board[0][0];
	int posX = 0, posY = 0;
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (max < board[x][y])
			{
				max = board[x][y];
				posX = x;
				posY = y;
			}
		}
	}

	std::cout << max << '\n';
	std::cout << (posX + 1) << ' ' << (posY + 1);

	return 0;
}