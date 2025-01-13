// Problem 25314
// https://www.acmicpc.net/problem/25314
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main(void)
//{
//	int input;
//
//	cin >> input;
//
//	int repeat = ceil(input / 4);
//	for (int i = 0; i < repeat; i++)
//	{
//		cout << "long ";
//	}
//
//	cout << "int";
//
//	return 0;
//}

// Problem 15552
// https://www.acmicpc.net/problem/15552
// 
// 참고 블로그
// https://dingcoding.tistory.com/62
// https://jaimemin.tistory.com/1521
#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int input;

	cin >> input;

	for (int i = 0; i < input; i++)
	{
		int temp1, temp2;

		cin >> temp1;
		cin >> temp2;

		cout << (temp1 + temp2) << "\n";
	}

	return 0;
}