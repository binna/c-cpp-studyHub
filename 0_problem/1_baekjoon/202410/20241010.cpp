// Problem 10813
// https://www.acmicpc.net/problem/10813
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, m;
//
//	cin >> n >> m;
//
//	vector<int> v(n);
//	for (int i = 0; i < v.size(); i++)
//	{
//		v[i] = i + 1;
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		int num1, num2;
//
//		cin >> num1 >> num2;
//
//		num1 -= 1;
//		num2 -= 1;
//
//		int temp = v[num1];
//		v[num1] = v[num2];
//		v[num2] = temp;
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << ' ';
//	}
//
//	
//	return 0;
//}

// Problem 5597
// https://www.acmicpc.net/problem/5597
//#include <iostream>
//using namespace std;
//
//int main(void)
//{ 
//	bool attendanceList[30] = { false };
//
//	for (int i = 0; i < 28; i++)
//	{
//		int attendanceStudent;
//		cin >> attendanceStudent;
//		attendanceList[attendanceStudent - 1] = true;
//	}
//
//	for (int i = 0; i < 30; i++)
//	{
//		if (!attendanceList[i])
//			cout << (i + 1) << '\n';
//	}
//	return 0;
//}

// Problem 3052
// https://acmicpc.net/problem/3052
//#include <iostream>
//#include <set>
//using namespace std;
//
//// s.size() : 원소의 개수를 반환
//// s.count(k) : 원소 k의 개수를 반환
//// s.empty() : 비어있는지 확인
//// s.insert(k) : 원소 k 삽입
//// s.erase(iter) : iter가 가리키는 원소를 제거
//
//int main(void)
//{
//	set<int> s;
//	for (int i = 0; i < 10; i++)
//	{
//		int num;
//
//		cin >> num;
//
//		s.insert(num % 42);
//	}
//
//	cout << s.size();
//
//	return 0;
//}

// https://www.acmicpc.net/problem/10811
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;

		cin >> start >> end;

		start -= 1;
		end -= 1;

		int repeatCount = (end - start) / 2;

		for (int j = start; j <= start + repeatCount; j++)
		{
			int temp = v[j];
			v[j] = v[end];
			v[end] = temp;

			end -= 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}

	return 0;
}