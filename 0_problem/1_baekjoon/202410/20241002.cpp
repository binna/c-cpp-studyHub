// Problem 11382
// https://www.acmicpc.net/problem/11382
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	long input1, input2, input3;
//
//	cin >> input1;
//	cin >> input2;
//	cin >> input3;
//
//	cout << input1 + input2 + input3;
//
//	return 0;
//}

// Problem 10171
// https://www.acmicpc.net/problem/10171
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	cout << "\\    /\\" << endl;
//	cout << " )  ( ')" << endl;
//	cout << "(  /  )" << endl;
//	cout << " \\(__)|" << endl;
//
//	return 0;
//}

// Problem 10172
// https://www.acmicpc.net/problem/10172
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	cout << "|\\_/|" << endl;
//	cout << "|q p|   /}" << endl;
//	cout << "( 0 )\"\"\"\\" << endl;
//	cout << "|\"^\"\`    |" << endl;
//	cout << "||_/=\\\\__|" << endl;
//
//	return 0;
//}

// Step 2 Start
// Problem 1330
// https://www.acmicpc.net/problem/
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
//	if (input1 < input2)
//		cout << "<";
//
//	else if (input1 > input2)
//		cout << ">";
//
//	else
//		cout << "==";
//
//	return 0;
//}

// Problem 9498
// https://www.acmicpc.net/problem/9498
#include <iostream>
using namespace std;

int main(void)
{
	int input;

	cin >> input;

	switch (input / 10)
	{
	case 10:
	case 9:
		cout << 'A';
		break;
	case 8:
		cout << 'B';
		break;
	case 7:
		cout << 'C';
		break;
	case 6:
		cout << 'D';
		break;
	default:
		cout << 'F';
		break;
	}

	return 0;
}