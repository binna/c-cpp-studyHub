// Problem 10988
// https://www.acmicpc.net/problem/10988
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(void)
//{
//	string inputWord;
//
//	cin >> inputWord;
//
//	int repeatNum = inputWord.length() / 2;
//	for (int i = 0; i < repeatNum; i++)
//	{
//		if (inputWord[i] != inputWord[inputWord.length() - 1 - i])
//		{
//			cout << 0;
//			return 0;
//		}
//	}
//
//	cout << 1;
//
//	return 0;
//}

// Problem 1157
// https://www.acmicpc.net/problem/1157
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	const int ALPHABAT_LENGHT = 26;

	int* alphabatCount = new int[ALPHABAT_LENGHT]();
	string alphabat;

	cin >> alphabat;

	for (int i = 0; i < alphabat.length(); i++)
	{
		int location = alphabat[i] - 'A';
		if (location < ALPHABAT_LENGHT)
		{
			alphabatCount[location] += 1;
			continue;
		}

		location = alphabat[i] - 'a';
		if (location < ALPHABAT_LENGHT)
		{
			alphabatCount[location] += 1;
		}
	}

	bool isAlready = false;
	int max = alphabatCount[0];
	char muchUsedAlphabat = 'A';

	for (int i = 1; i < ALPHABAT_LENGHT; i++)
	{
		if (max < alphabatCount[i])
		{
			isAlready = false;
			max = alphabatCount[i];
			muchUsedAlphabat = (char)('A' + i);
			continue;
		}

		if (max == alphabatCount[i])
		{
			isAlready = true;
		}
	}

	if (isAlready)
		cout << "?";
	else
		cout << muchUsedAlphabat;

	return 0;
}