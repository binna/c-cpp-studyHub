#include <stdio.h>

int WhoIsFirst(int age1, int age2, int (*cmp)(int, int))
{
	return cmp(age1, age2);
}

int OlderFirst(int age1, int age2)
{
	if (age1 > age2)
	{
		return age1;
	}
	else if (age1 < age2)
	{
		return age2;
	}
	return 0;
}

int YoungFirst(int age1, int age2)
{
	if (age1 < age2)
	{
		return age1;
	}
	else if (age1 > age2)
	{
		return age2;
	}
	return 0;
}

int main(void)
{
	int age1 = 20;
	int age2 = 30;
	int first;

	printf("입장순서1\n");
	first = WhoIsFirst(age1, age2, OlderFirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장!\n\n", age1, age2, first);

	printf("입장순서2\n");
	first = WhoIsFirst(age1, age2, YoungFirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장!\n\n", age1, age2, first);

	return 0;
}