// Problem 11021
// https://www.acmicpc.net/problem/11021
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int repeatNum;
//
//	cin >> repeatNum;
//
//	for (int i  = 0; i < repeatNum; i++)
//	{
//		int temp1, temp2;
//
//		cin >> temp1;
//		cin >> temp2;
//
//		cout << "Case #" << i + 1 << ": " << (temp1 + temp2) << endl;
//	}
//	return 0;
//}

// Problem 11022
// https://www.acmicpc.net/problem/11022
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
//		int temp1, temp2;
//
//		cin >> temp1;
//		cin >> temp2;
//
//		cout << "Case #" << (i + 1) << ": " << temp1 << " + " << temp2 
//			<< " = " << (temp1 + temp2)<< '\n';
//	}
//}

// Problem 2438
// https://www.acmicpc.net/problem/2438
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
//		for (int j = 0; j < i + 1; j++)
//			cout << "*";
//
//		cout << '\n';
//	}
//
//	return 0;
//}

// Problem 2439
// https://www.acmicpc.net/problem/2439
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
//		for (int j = 0; j < repeatNum - i - 1; j++)
//			cout << " ";
//
//		for (int j = 0; j < i + 1; j++)
//			cout << "*";
//
//		cout << '\n';
//	}
//	return 0;
//}

// Problem 10952
// https://www.acmicpc.net/problem/10952
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	while (true)
//	{
//		int temp1, temp2;
//
//		cin >> temp1;
//		cin >> temp2;
//
//		if (temp1 == 0 && temp2 == 0)
//			break;
//
//		cout << (temp1 + temp2) << '\n';
//	}
//}

// Problem 10951
// https://www.acmicpc.net/problem/10951

// 참고 블로그
// https://st-lab.tistory.com/257
#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		int temp1, temp2;

		if ((cin >> temp1).eof())
			break;
		
		if ((cin >> temp2).eof())
			break;

		cout << (temp1 + temp2) << '\n';
	}

	return 0;
}