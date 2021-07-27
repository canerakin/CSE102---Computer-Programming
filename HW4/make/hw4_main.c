#include <stdio.h>
#include "hw4_lib.h"
#include "hw4_io.h"
/*main fonksiyonu gönderilmiş halinden hiç değiştirilmemiş bir şekildedir*/
void test_compare_derivates()
{
	double f(double x)
	{
		return (x * x);
	}
	double d1(double x)
	{
		return (2.0 * x);
	}
	double d2(double x)
	{
		return (2.0);
	}
	double e1 , e2;
	int res = compare_derivatives(f ,d1 ,d2 ,1.0 ,0.0001 ,&e1 ,&e2);
	printf("%f %f\n",e1 ,e2);
}

int main(void)
{
	test_compare_derivates();
	return 0;
}

