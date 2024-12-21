// Problem 9086
// https://www.acmicpc.net/problem/9086
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int repeatNum;
//
//	cin >> repeatNum;
//
//	for (int i = 0; i < repeatNum; i++)
//	{
//		string text;
//
//		cin >> text;
//		
//		int size = text.size();
//		if (size <= 1)
//		{
//			cout << text[0] << text[0] << '\n';
//			continue;
//		}
//
//		cout << text[0] <<  text[size - 1] << '\n';
//	}
//	return 0;
//}

// Problem
// https://www.acmicpc.net/problem/11654
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	char inputChar;
//
//	cin >> inputChar;
//
//	cout << (int)inputChar;
//
//	return 0;
//}

// problem 11720
// https://www.acmicpc.net/problem/11720
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int repeatNum;
//	string targetSumNum;
//
//	cin >> repeatNum >> targetSumNum;
//
//	long long sumNum = 0;
//	for (int i = 0; i < repeatNum; i++)
//	{
//		sumNum += (int)(targetSumNum[i] - '0');
//	}
//
//	cout << sumNum;
//
//	return 0;
//}

// Problem 10809
// https://www.acmicpc.net/problem/10809
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int result[26];
//	int resultLen = sizeof(result) / sizeof(int);
//
//	string text;
//
//	cin >> text;
//
//	for (int i = 0; i < resultLen; i++)
//	{
//		result[i] = -1;
//	}
//
//	for (int i = 0; i < text.size(); i++)
//	{
//		if (result[(int)(text[i] - 'a')] == -1)
//			result[(int)(text[i] - 'a')] = i;
//	}
//
//	for (int i = 0; i < resultLen; i++)
//	{
//		cout << result[i] << ' ';
//	}
//	
//	return 0;
//}

// Problem
// https://www.acmicpc.net/problem/2675
#include <iostream>
using namespace std;

int main(void)
{
	int repeatNum;

	cin >> repeatNum;

	for (int i = 0; i < repeatNum; i++)
	{
		int repeatCount;
		string text;

		cin >> repeatCount >> text;

		for (int j = 0; j < text.size(); j++)
		{
			for (int z = 0; z < repeatCount; z++) 
			{
				cout << text[j];
			}
		}
		cout << '\n';
	}

	return 0;
}