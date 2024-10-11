// Problem 2739
// https://www.acmicpc.net/problem/2739
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int input;
//
//	cin >> input;
//
//	for (int i = 1; i <= 9; i++)
//	{
//		cout << input << " * " << i << " = " << input * i << endl;
//	}
//
//	return 0;
//}

// Problem 10950
// https://www.acmicpc.net/problem/10950
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int repeat;
//
//	cin >> repeat;
//
//	for (int i = 0; i < repeat; i++)
//	{
//		int temp1, temp2;
//
//		cin >> temp1;
//		cin >> temp2;
//
//		cout << temp1 + temp2 << endl;
//	}
//
//	return 0;
//}

// Problem 8393
// https://www.acmicpc.net/problem/8393
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int result = 0;
//
//	int input;
//
//	cin >> input;
//	
//	for (int i = 1; i <= input; i++)
//	{
//		result += i;
//	}
//
//	cout << result;
//
//	return 0;
//}

// Problem 25304
// https://www.acmicpc.net/problem/25304
#include <iostream>
using namespace std;

int main(void)
{
	int result = 0;

	int input1, input2;

	cin >> input1;
	cin >> input2;

	for (int i = 0; i < input2; i++)
	{
		int temp1, temp2;

		cin >> temp1;
		cin >> temp2;

		result += temp1 * temp2;
	}

	cout << (input1 == result ? "Yes" : "No");

	return 0;
}