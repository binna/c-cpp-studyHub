// Problem 5622
// https://www.acmicpc.net/problem/5622
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	const int Dial[] = {
//		2, 2, 2,
//		3, 3, 3,
//		4, 4, 4,
//		5, 5, 5,
//		6, 6, 6,
//		7, 7, 7, 7,
//		8, 8, 8,
//		9, 9, 9, 9
//	};
//
//	string Text;
//	cin >> Text;
//
//	int result = Text.length();
//
//	for (int i = 0; i < Text.length(); i++)
//	{
//		result += Dial[Text[i] - 'A'];
//	}
//
//	cout << result;
//	
//	return 0;
//}

// Problem 11718
// https://www.acmicpc.net/problem/11718

// 문제 해결할때 참고한 블로그
// https://goalsdhkdwk.tistory.com/entry/BOJ%EB%B0%B1%EC%A4%80-11718%EB%B2%88-%EA%B7%B8%EB%8C%80%EB%A1%9C-%EC%B6%9C%EB%A0%A5%ED%95%98%EA%B8%B0-cc-%ED%92%80%EC%9D%B4
// getline
// 공백을 포함한 한 줄을 입력 받아, 파라미터로 입력된 변수에 저장
// 입력된 값이 없을 경우 ""로 저장 <- 중요한 해결 포인트
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string input;

	while(true)
	{
		getline(cin, input);

		if (input == "")
			break;

		cout << input << endl;
	}

	return 0;
}