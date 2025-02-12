#include <stdio.h>

char* ResultName(void)
{
	char name[30];
	printf("What's your name? ");
	gets(name);
	return name;
}

int main(void)
{
	char* name1;
	char* name2;

	name1 = ResultName();
	printf("name1 : %s\n", name1);

	name2 = ResultName();
	printf("name2 : %s\n", name2);
	
	return 0;
}