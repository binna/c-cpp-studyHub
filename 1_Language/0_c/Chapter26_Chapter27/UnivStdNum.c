#include <stdio.h>

#define STNUM1(Y,S,P)	#Y#S#P
#define STNUM2(Y,S,P)	Y""S""P""
#define STNUM3(Y,S,P)	Y S P
#define STNUM4(Y,S,P)	((Y)*(100000) + (S)*(1000) + (P))

#define CON(UPP, LOW)	UPP ## 00 ## LOW
#define STNUM5(Y,S,P)	Y ## S ## P

int main(void)
{
	printf("%s\n", STNUM1(10, 65, 175));
	printf("%s\n", STNUM2("10", "65", "175"));
	printf("%s\n", STNUM3("10", "65", "175"));
	printf("%d\n", STNUM4(10, 65, 175));
	printf("%d\n", CON(22, 77));
	printf("%d\n", STNUM5(10, 65, 175));

	return 0;
}