// Problem 10869
// https://www.acmicpc.net/problem/10869
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int input1, input2;
//	
//	cin >> input1;
//	cin >> input2;
//
//	cout << input1 + input2 << endl;
//	cout << input1 - input2 << endl;
//	cout << input1 * input2 << endl;
//	cout << input1 / input2 << endl;
//	cout << input1 % input2 << endl;
// 
//	return 0;
//}

// Problem 10926
// https://www.acmicpc.net/problem/10926
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	string input;
//
//	cin >> input;
//
//	cout << input + "??!";
//
//	return 0;
//}

// Problem 18108
// https://www.acmicpc.net/problem/18108
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int input;
//
//	cin >> input;
//
//	cout << input - 543;
//
//	return 0;
//}

// Problem 10430
// https://www.acmicpc.net/problem/10430
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int input1, input2, input3;
//
//	cin >> input1;
//	cin >> input2;
//	cin >> input3;
//
//	cout << (input1 + input2) % input3 << endl;
//	cout << ((input1 % input3) + (input2 % input3)) % input3 << endl;
//	cout << (input1 * input2) % input3 << endl;
//	cout << ((input1 % input3) * (input2 % input3)) % input3 << endl;
//
//	return 0;
//}

// Problem 2588
// https://www.acmicpc.net/problem/2588
#include <iostream>
using namespace std;

int main(void)
{
	int input1, input2;
	
	cin >> input1;
	cin >> input2;

	cout << input1 * (input2 % 10) << endl;
	cout << input1 * ((input2 % 100) / 10) << endl;
	cout << input1 * ((input2 % 1000) / 100) << endl;
	cout << input1 * input2 << endl;

	return 0;
}