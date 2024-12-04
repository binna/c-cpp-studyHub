// Problem 2941
// https://www.acmicpc.net/problem/2941
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(void)
//{
//	int count = 0;
//
//	string text;
//	cin >> text;
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		char temp = text[i + 1];
//		switch (text[i])
//		{
//		case 'c':
//			if (temp == '=' || temp == '-')
//				i += 1;
//
//			break;
//		case 'd':
//			if (temp == 'z')
//			{
//				if (text[i + 2] == '=')
//					i += 2;
//			}
//
//			if (temp == '-')
//				i += 1;
//			break;
//		case 'l':
//			if (temp == 'j')
//				i += 1;
//			break;
//		case 'n':
//			if (temp == 'j')
//				i += 1;
//			break;
//		case 's':
//			if (temp == '=')
//				i += 1;
//			break;
//		case 'z':
//			if (temp == '=')
//				i += 1;
//			break;
//		}
//
//		count += 1;
//	}
//
//	cout << count;
//
//	return 0;
//}

// Problem 1316
// https://www.acmicpc.net/problem/1316
//#include <iostream>
//#include <set>
//using namespace std;
//
//int main(void)
//{
//	int count = 0;
//	int repeatNum;
//	
//	set<char> s;
//
//	cin >> repeatNum;
//
//	for (int i = 0; i < repeatNum; i++)
//	{
//		bool isWord = true;
//		string text;
//
//		cin >> text;
//
//		s.clear();
//		
//		for (int i = 0; i < text.length(); i++)
//		{
//			if (s.find(text[i]) != s.end())
//				isWord = false;
//
//			s.insert(text[i]);
//
//			char target = text[i + 1];
//			while (target == text[i])
//			{
//				i += 1;
//				target = text[i + 1];
//			}
//		}
//		if (isWord) { count++; }
//	}
//
//	cout << count;
//
//	return 0;
//}

// Problem 25206
// https://www.acmicpc.net/problem/25206
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main(void)
{
	map<string, double> m
	{
		{"A+" , 4.5},
		{"A0" , 4.0},
		{"B+" , 3.5},
		{"B0" , 3.0},
		{"C+" , 2.5},
		{"C0" , 2.0},
		{"D+" , 1.5},
		{"D0" , 1.0},
		{"F" , 0.0},
	};

	double creditSum = 0;
	double subjectSum = 0;
	for (int i = 0; i < 20; i++)
	{
		string text;
		string word;

		vector<string> v;

		getline(cin, text);

		stringstream ss(text);

		ss.str(text);

		while (ss >> word)
		{
			v.push_back(word);
		}

		if (v[2] == "P")
			continue;

		creditSum += stod(v[1]);
		subjectSum += (stod(v[1]) * m[v[2]]);
	}

	cout << (subjectSum / creditSum);

	return 0;
}