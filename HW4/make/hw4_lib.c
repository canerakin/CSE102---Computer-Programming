#include <stdio.h>
#include "hw4_lib.h"

double integral(double f(double x) ,double xs ,double xe ,double delta)/*tek katlı integralini alma*/
{
	double x , h1, h2 , toplam = 0; /*sırasıyla anlık değer anlık yükseklik ve bir sonraki yüksekliği tanımladım*/
	x = xs;/*alt sınırın üzerinde yapacağım değişiklikler için yeni bir değere atadım*/

	while(x < xe)/*üst sınıra varana dek devam edecek while döngüsü*/
	{
		h1 = f(x); /*anlık yükseklik*/
		h2 = f(x + delta);/*bir sonraki yüksekliğide alarak hangisi daha kısa ise onu kullanırım*/
		if (h1 < h2)/*h1 kısa ise işleme girer*/
		{
			toplam = toplam + (h1 * delta);			
		}
		else/*diğer durumlarda ise h2 işleme girer*/
		{
			toplam = toplam + (h2 * delta);	
		}

		x = x + delta; /*her seferinde delta kadar xe'ye yaklaşır*/
	}
	
	return toplam;/*sonuc return edilir*/	
}

double integral2(double f(double x , double y) ,double xs ,double xe ,double ys ,double ye ,double delta)/*çift katlı integralini alma*/
{
	double x , y , toplam = 0 , anlik_sayi;/*sırasıyla alt sınırlar sonuc ve anlık sonuc*/
	x = xs;/*alt sınır yeni bir değişkene atanarak üstünde değişiklikler yapılabilir*/
	y = ys;/*alt sınır yeni bir değişkene atanarak üstünde değişiklikler yapılabilir*/

	while(x <= xe) /*üst sınıra varana kadar devam eder*/
	{
		y = ys;/*her seferinde alt sınıra tekrardan dönsün diye değer tekrardan atanır*/
		while(y <= ye)/*üst sınıra varana kadar devam eder*/
		{
			anlik_sayi = f(x ,y) * delta * delta;/*küçük karaler halinde bulunan kordinatlardaki anlık değer*/
			toplam = toplam + anlik_sayi;/*anlık değer her seferinde sonuca eklenir*/
			y = y + delta;	/*üst sınıra varana kadar eklenir*/	
		}
		x = x + delta;/*üst sınıra varana kadar eklenir.*/
	}
	return toplam;	/*sonuc return edilir*/	
}

int derivatives(double f(double a) ,double x ,double eps ,double *d1 ,double *d2)/*çift katlı türev alma fonksiyonu*/
{
	if (eps != 0)/*bölüm kısmı 0 olmadığı sürece işlemler gerçekleşir*/
	{
		*d1 = (f(x + eps) - f(x - eps) ) / (2 * eps);/*formül 1.türeve işlenir*/ 
		*d2 = (f(x + eps) - (2 * f(x)) + f(x - eps) ) / (eps * eps);/*formül 2.türeve işlenir*/
		return 1;/*istenilen olduğunda 1 değerini döndürür*/
	}
	else/*else kısmı eps == 0 olduğu durumu kapsar*/
	{
		return -1;/*bu durumda -1 return eder*/
	}
}

int compare_derivatives(double f(double a) ,double d1(double b) ,double d2(double b) ,double x ,double eps ,double *e1 ,double *e2)/*bağıl hatayı bulan fonksiyon*/
{
	double d_1 , d_2 , k , b;/*sırasıyla 1.türev 2.türev ve derivatives fonksiyonu döngüsü*/
	k = derivatives(f ,x ,eps ,&d_1 ,&d_2);/*derivatives fonksiyonunu çağırdım*/

	*e1 = d_1 - d1(b); /*bağıl hata hesaplanması*/
	*e2 = d_2 - d2(b);/*bağıl hata hesaplanması*/

	if (*e1 < 0)/*negatif olduğu durumlarda buraya girer*/
	{
		*e1 = *e1 * (-1);/*bir nevi mutlak değer almak için bu işlem kullanılır*/
	}
	if (*e2 < 0)/*negatif olduğu durumlarda buraya girer*/
	{
		*e2 = *e2 * (-1);/*bir nevi mutlak değer almak için bu işlem kullanılır*/
	}

	return (0);
}

int find_roots(double f(double x) ,double *x1 ,double *x2 ,double *x3 ,double *x4)/*kok bulma fonksiyonu*/
{
	int flag = 0;/*kaç tane kok bulduğunu hesaplar*/
	double kok ,sinir = -200.0;/*sınır tanımlanır*/ 
	while(sinir <= 200 && flag <= 3)/*sınırlar boyunca döner*/
	{
		kok = f(sinir);/*her sayı tek tek denenir*/
		if (flag == 0 && kok == 0)/*ilk kökü bulmak için buraya girer */
		{
			*x1 = kok;
			flag = flag + 1; /*bir sonraki kökü araması için*/
		}
		else if (flag == 1 && kok == 0)/*ikinci kökü bulmak için buraya girer */
		{
			*x2 = kok;
			flag = flag + 1;/*bir sonraki kökü araması için*/ 
		}
		else if (flag == 2 && kok == 0)/*üçüncü kökü bulmak için buraya girer */
		{
			*x3 = kok;
			flag = flag + 1; /*bir sonraki kökü araması için*/
		}
		else if (flag == 3 && kok == 0)/*dördüncü kökü bulmak için buraya girer */
		{
			*x4 = kok;
			flag = flag + 1;/*döngüden çıksın diye*/
		}
		sinir = sinir + 0.001;/*sınır küçük aralıklarla artar*/
	}
	if (flag == 4)/*tüm kökler bulunmuşsa 1 returnler*/
	{
		return 1;
	}
	else/*tüm kökler bulunmamışsa 0 returnler*/
	{
		return 0;
	}



	return 0;	
}