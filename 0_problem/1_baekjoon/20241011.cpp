// Problem 1546
// https://www.acmicpc.net/problem/1546
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	int num;
//
//	double max{}, tatalNum = 0;
//
//	cin >> num;
//
//	vector<int> v(num);
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> v[i];
//		
//		if (i == 0)
//			max = v[i];
//		else if (max < v[i])
//			max = v[i];
//	}
//
//	for (int i = 0; i < num; i++)
//	{
//		tatalNum += (v[i] / max * 100);
//	}
//
//	cout << tatalNum / num;
//
//	return 0;
//}

// Problem 27866
// https://www.acmicpc.net/problem/27866
//#include <iostream>
//#include <string>
//using namespace std;
//
////int main(void)
////{
////	string text;
////	int targetPos;
////	
////	cin >> text >> targetPos;
////
////	char resultCharacter{};
////	for (int i = 0; i < targetPos; i++)
////	{
////		resultCharacter = text[i];
////	}
////
////	cout << resultCharacter;
////
////	return 0;
////}
//
//// 다른 사람 풀이
//// https://goalsdhkdwk.tistory.com/entry/BOJ%EB%B0%B1%EC%A4%80-27866%EB%B2%88-%EB%AC%B8%EC%9E%90%EC%99%80-%EB%AC%B8%EC%9E%90%EC%97%B4-cc-%ED%92%80%EC%9D%B4
//int main(void)
//{
//	string text;
//	int targetPos;
//
//	cin >> text >> targetPos;
//
//	cout << text[targetPos - 1];
//}

// Problem 2743
// https://www.acmicpc.net/problem/2743
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string Text;

	cin >> Text;

	cout << Text.size();

	return 0;
}