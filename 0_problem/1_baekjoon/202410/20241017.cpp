// Problem 25083
// https://www.acmicpc.net/problem/25083
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	cout << "         ,r\'\"7" << '\n';
//	cout << "r`-_   ,'  ,/" << '\n';
//	cout << " \\. \". L_r\'"<< '\n';
//	cout << "   `~\\/" << '\n';
//	cout << "      |" << '\n';
//	cout << "      |" << '\n';
//	return 0;
//}

// Problem 3003
// https://www.acmicpc.net/problem/3003
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int peaceCount = 6;
//	int chessPeace[] = {1,1,2,2,2,8};
//
//	for (int i = 0; i < peaceCount; i++)
//	{
//		int peace;
//		cin >> peace;
//		cout << (chessPeace[i] - peace) << " ";
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;

int main(void)
{
	int repeatNum;

	cin >> repeatNum;

	int temp = 0;
	for (int i = 0; i < repeatNum - 1; i++)
	{
		for (int j = repeatNum - (i + 2); j >= 0; j--)
		{
			cout << ' ';
		}

		for (int j = 0; j <= i + temp; j++)
		{
			cout << '*';
		}
		
		temp = i + 1;
		cout << '\n';
	}

	for (int i = 0; i < repeatNum; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}

		for (int j = repeatNum + temp - i; j > 0; j--)
		{
			cout << '*';
		}

		temp -= 1;
		cout << '\n';
	}
	return 0;
}