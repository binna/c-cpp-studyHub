#include <stdio.h>

int main(void)
{
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;
	double* ptr2;

	printf("%9p %9p\n", ptr, *dptr);
	printf("%9g %9g\n", num, **dptr);

	printf("\nnum狼 林家 : %p(%d),  ptr狼 林家 : %p, ptr2狼 林家 %p, dptr狼 林家 : %p\n\n", 
		&num, &num, &ptr, &ptr2, &dptr);

	ptr2 = *dptr;
	*ptr2 = 10.99;
	printf("%9g %9g %9g\n", num, **dptr, *ptr2);

	return 0;
}