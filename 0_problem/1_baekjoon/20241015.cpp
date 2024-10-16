// Problem 1152
// https://www.acmicpc.net/problem/1152

// 문제 해결을 위해 참고한 블로그
// https://cryptosalamander.tistory.com/136
// #include <string>
// string str;
// getline(cin, str);

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(void)
//{
//	string text;
//	int result = 0;
//
//	getline(cin, text);
//
//	char buffer = text[0];
//
//	for (int i = 1; i < text.size(); i++)
//	{
//		if (buffer == ' ')
//		{
//			buffer = text[i];
//			continue;
//		}
//		
//		if (text[i] == ' ')
//		{
//			result += 1;
//		}
//		buffer = text[i];
//	}
//
//	if (buffer != ' ')
//	{
//		result += 1;
//	}
//
//	cout << result;
//
//	return 0;
//}

// Problem 2908
// https://www.acmicpc.net/problem/2908

// 문제 해결을 위해 참고한 블로그
// https://blockdmask.tistory.com/334
// https://blockdmask.tistory.com/333

// #include <string>
// to_string(숫자);

// stoi = string to int
// stof = string to float
// stol = string to long
// stod = string to double

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int num1, num2;

	cin >> num1 >> num2;

	string strNum1 = to_string(num1);
	for (int i = 0; i < strNum1.length() / 2; i++)
	{
		int idx = strNum1.length() - 1 - i;
		int temp = strNum1[i];
		strNum1[i] = strNum1[idx];
		strNum1[idx] = temp;
	}

	string strNum2 = to_string(num2);
	for (int i = 0; i < strNum2.length() / 2; i++)
	{
		int idx = strNum2.length() - 1 - i;
		int temp = strNum2[i];
		strNum2[i] = strNum2[idx];
		strNum2[idx] = temp;
	}

	num1 = stoi(strNum1);
	num2 = stoi(strNum2);

	if (num1 > num2)
		cout << num1;
	else
		cout << num2;

	return 0;
}