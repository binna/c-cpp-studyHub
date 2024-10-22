// Problem 2753
// https://www.acmicpc.net/problem/2753
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int input;
//
//	cin >> input;
//
//	if (input % 4 == 0 && (input % 100 != 0 || input % 400 == 0))
//		cout << 1;
//	else
//		cout << 0;
//
//	return 0;
//}

// Problem 14681
// https://www.acmicpc.net/problem/14681
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int x, y;
//
//	cin >> x;
//	cin >> y;
//
//	if (x > 0)
//	{
//		if (y > 0)
//			cout << 1;
//		else
//			cout << 4;
//	}
//	else 
//	{
//		if (y > 0)
//			cout << 2;
//		else
//			cout << 3;
//	}
//
//	return 0;
//}

// Problem 2884
// https://www.acmicpc.net/problem/2884
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int h, m;
//
//	cin >> h;
//	cin >> m;
//
//	int earlyMinute = 45;
//
//	if (m < earlyMinute)
//	{
//		h = h - 1;
//
//		if (h == -1)
//			h = 23;
//
//		m = m + 60 - earlyMinute;
//	}
//	else 
//	{
//		m = m - earlyMinute;
//	}
//
//	cout << h << " " << m;
//
//	return 0;
//}

// Problem 2525
// https://www.acmicpc.net/problem/2525
//#include <iostream>
//using namespace std;
//int main(void)
//{
//	int h, m, cookingTime;
//
//	cin >> h;
//	cin >> m;
//	cin >> cookingTime;
//
//	m += cookingTime;
//
//	h += m / 60;
//	m = m % 60;
//
//	if (h >= 24)
//	{
//		h -= 24;
//	}
//
//	cout << h << " " << m;
//
//	return 0;
//}

// Problem 2480
// https://www.acmicpc.net/problem/2480
#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, num3;

	cin >> num1;
	cin >> num2;
	cin >> num3;

	if (num1 == num2 && num2 == num3 && num1 == num3)
	{
		cout << 10000 + num1 * 1000;
	}
	else if (num1 != num2 && num2 != num3 && num1 != num3)
	{
		int temp = max(num1, num2);
		cout << max(temp, num3) * 100;
	}
	else
	{
		if (num2 == num3)
			cout << 1000 + num2 * 100;
		else
			cout << 1000 + num1 * 100;
	}

	return 0;
}