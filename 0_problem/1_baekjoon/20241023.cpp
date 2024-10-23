#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(void)
{
	int n, m;

	cin >> n >> m;

	cin.ignore();

	vector<int> inputMatrix(n * m * 2);

	int count = 0;
	for (int i = 0; i < n * 2; i++)
	{
		string str;
		getline(cin, str);

		stringstream ss(str);
		ss.str(str);
		string temp;

		while (ss >> temp)
		{
			inputMatrix[count++] = stoi(temp);
		}
	}

	vector<vector<vector<int>>> matrix(n, vector<vector<int>>(m, (vector<int> (2, 0))));

	int idx = 0;
	for (int z = 0; z < 2; z++)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				matrix[x][y][z] = inputMatrix[idx++];
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << (matrix[i][j][0] + matrix[i][j][1]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}