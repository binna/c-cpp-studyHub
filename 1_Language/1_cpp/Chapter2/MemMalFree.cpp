#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

char* MakeStrAdr(int len)
{
	char* str = (char*)malloc(sizeof(char) * len);
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy_s(str, 20, "I am so happy");
	cout << str << endl;
	free(str);

	return 0;
}