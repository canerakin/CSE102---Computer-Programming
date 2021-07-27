#include <stdio.h>
#include "hw4_io.h"

int read_polynomial3(double * a0 ,double * a1 ,double * a2 ,double * a3)/*3 katlı polinomun başkatsayısını alma fonksiyonu*/
{
	printf("enter the coefficient of x with coefficient 0:");/*x üzeri 0'ın katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a0);
	printf("enter the coefficient of x with coefficient 1:");/*x üzeri 1'in katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a1);
	printf("enter the coefficient of x with coefficient 2:");/*x üzeri 2'nin katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a2);
	printf("enter the coefficient of x with coefficient 3:");/*x üzeri 3'ün katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a3);
	return 0;/*döndürmesi gereken herhangi bir sayı olmadığı için 0 döndürür*/
}

int read_polynomial4(double * a0 ,double * a1 ,double * a2 ,double * a3 ,double * a4)/*4 katlı polinomun başkatsayılarını alma fonksiyonu*/
{
	printf("enter the coefficient of x with coefficient 0:");/*x üzeri 0'ın katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a0);
	printf("enter the coefficient of x with coefficient 1:");/*x üzeri 1'in katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a1);
	printf("enter the coefficient of x with coefficient 2:");/*x üzeri 2'nin katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a2);
	printf("enter the coefficient of x with coefficient 3:");/*x üzeri 3'ün katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a3);
	printf("enter the coefficient of x with coefficient 4:");/*x üzeri 4'ün katsayısı kullanıcıdan alınır*/
	scanf("%lf",&*a4);
	return 0;/*döndürmesi gereken herhangi bir sayı olmadığı için 0 döndürür*/
}

void write_polynomial3(double a0 ,double a1 ,double a2 ,double a3)/*x üzeri 3 üslü polinomu ekrana yazma fonksiyonu*/
{
	int k;
	k = read_polynomial3(&a0 ,&a1 ,&a2 ,&a3);/*diğer fonksiyondan pointer ile değerlerin hepsi çağırılır*/
	if (a3 != 0)/*x üzeri 3'ün katsayısı ile ekrana yazılması*/
	{
		if (a3 == 1.0)
		{
			printf("+x^3 ");
				
		}
		else if (a3 == -1.0)
		{
			printf("-x^3 ");
		}
		else
		{
			printf("%.1lfx^3 ",a3);
		}	
	}
	if (a2 > 0)/*x üzeri 2'nin + ise katsayısı ile ekrana yazılması*/
	{
		if (a2 != 1.0)
		{
			printf("%.1lfx^2 ",a2);	
		}
		else
		{
			printf("+x^2 ");	
		}		
	}
	else if (a2 < 0)/*x üzeri 2'nin - ise katsayısı ile ekrana yazılması*/
	{
		if (a2 != -1.0)
		{
			printf("%.1lfx^2 ",a2);	
		}
		else
		{
			printf("-x^2 ");	
		}
	}
	if (a1 > 0)/*x üzeri 1'in + ise katsayısı ile ekrana yazılması*/
	{
		if (a1 != 1.0)
		{
			printf("%.1lfx^1 ",a1);	
		}
		else
		{
			printf("+x^1 ");	
		}		
	}
	else if (a1 < 0)/*x üzeri 1'in - ise katsayısı ile ekrana yazılması*/
	{
		if (a1 != -1.0)
		{
			printf("%.1lfx^1 ",a1);	
		}
		else
		{
			printf("-x^1 ");	
		}
	}
	if (a0 > 0)/*x üzeri 0'ın + ise katsayısı ile ekrana yazılması*/
	{
		printf("+%.1lf ",a0);		
	}
	else if (a0 < 0)/*x üzeri 0'ın - ise katsayısı ile ekrana yazılması*/
	{
		printf("%.1lf ",a0);
	}
	printf("\n");
}

void write_polynomial4(double a0 ,double a1 ,double a2 ,double a3 ,double a4)
{
	int z;
	z = read_polynomial4(&a0 ,&a1 ,&a2 ,&a3 ,&a4);/*diğer fonksiyondan pointer ile değerlerin hepsi çağırılır*/
	if (a4 != 0)/*x üzeri 4'ün katsayısı ile ekrana yazılması*/
	{
		if (a4 == 1.0 )
		{
			printf("+x^4 ");
				
		}
		else if (a4 == -1.0)
		{
			printf("-x^4 ");
		}
		else
		{
			printf("%.1lfx^4 ",a4);
		}	
	}

	if (a3 > 0)/*x üzeri 3'ün + ise katsayısı ile ekrana yazılması*/
	{
		if (a3 != 1.0)
		{
			printf("%.1lfx^3 ",a3);	
		}
		else
		{
			printf("+x^3 ");	
		}		
	}		
	
	else if (a3 < 0)/*x üzeri 3'ün - ise katsayısı ile ekrana yazılması*/
	{
		if (a3 != -1.0)
		{
			printf("%.1lfx^3 ",a2);	
		}
		else
		{
			printf("-x^3 ");	
		}		
	}
	
	
	if (a2 > 0)/*x üzeri 2'nin + ise katsayısı ile ekrana yazılması*/
	{
		if (a2 != 1.0)
		{
			printf("%.1lfx^2 ",a2);	
		}
		else
		{
			printf("+x^2 ");	
		}				
	}

	else if (a2 < 0)/*x üzeri 2'nin - ise katsayısı ile ekrana yazılması*/
	{
		if (a2 != -1.0)
		{
			printf("%.1lfx^2 ",a2);	
		}
		else
		{
			printf("-x^2 ");	
		}		
	}

	if (a1 > 0)/*x üzeri 1'ın + ise katsayısı ile ekrana yazılması*/
	{
		if (a1 != 1.0)
		{
			printf("%.1lfx^1 ",a1);	
		}
		else
		{
			printf("+x^1 ");	
		}				
	}

	else if (a1 < 0)/*x üzeri 1'in - ise katsayısı ile ekrana yazılması*/

	{
		if (a1 != -1.0)
		{
			printf("%.1lfx^1 ",a1);	
		}
		else
		{
			printf("-x^1 ");	
		}		
	}

	if (a0 > 0)/*x üzeri 0'ın + ise katsayısı ile ekrana yazılması*/
	{
		printf("+%.1lf ",a0);		
	}
	else if (a0 < 0)/*x üzeri 0'ın - ise katsayısı ile ekrana yazılması*/

	{
		printf("%.1lf ",a0);
	}
	printf("\n");
}

