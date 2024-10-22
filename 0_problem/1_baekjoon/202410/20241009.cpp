// Problem 10871
// https://www.acmicpc.net/problem/10871
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int repeatNum, standardNum;
//
//	cin >> repeatNum >> standardNum;
//
//	for (int i = 0; i < repeatNum; i++)
//	{
//		int temp;
//
//		cin >> temp;
//
//		if (temp < standardNum)
//		{
//			cout << temp << ' ';
//		}
//	}
//	return 0;
//}

// Problem 10818
// https://www.acmicpc.net/problem/10818
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int repeatNum;
//	
//	int min, max;
//
//	cin >> repeatNum;
//
//	vector<int> v(repeatNum);
//
//	for (int i = 0; i < repeatNum; i++)
//	{
//		cin >> v[i];
//	}
//
//	min = v[0];
//	max = v[0];
//	for (int i = 1; i < repeatNum; i++)
//	{
//		if (min > v[i])
//			min = v[i];
//		else if (max < v[i])
//			max = v[i];
//	}
//
//	cout << min << ' ' << max;
//	return 0;
//}

// Problem 2562
// https://www.acmicpc.net/problem/2562
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int arr[9], idx, max;
//
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> arr[i];
//	}
//
//	idx = 0, max = arr[0];
//	for (int i = 1; i < 9; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//			idx = i;
//		}
//	}
//
//	cout << max << '\n' << (idx + 1);
//	return 0;
//}

// Problem 10810
// https://www.acmicpc.net/problem/10810

// 참고한 블로그
// https://velog.io/@she_is_so_chic/BOJ-%EB%B0%B1%EC%A4%80-10810%EB%B2%88-%EA%B3%B5%EB%84%A3%EA%B8%B0%EA%B5%AC%ED%98%84
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	vector<int> stage(n);

	for (int i = 0; i < m; i++)
	{
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;

		for (int j = temp1 - 1; j < temp2; j++)
		{
			stage[j] = temp3;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << stage[i] << " ";
	}

	return 0;
}