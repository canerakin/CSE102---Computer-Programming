/*Caner AKIN
151044066*/
#include <stdio.h>/*standart input output kütüphanesi*/

int main()
{
	int number ,first ,second ,third , fourth ,fifth;
	number = 22; /*while döngüsüne ilk olarak girebilmesi için bir değer atadım*/

	while(number <=22 || number >=98761)/*istanilen değer girilmediği sürece yeni değer isteyecek olan while döngüsüdür*/
	{

		printf("Enter a number:");
		scanf("%d",&number); /*döngünün icine girdikten sonra bu degeri kullanıcıdan alınmaya baslar*/
	
		if (number >= 10000 && number <= 98760)/*sayı 5 haneliyse ilk buraya girer ve sırayla diger iflerede girer*/
		{
			fifth = number / 10000; /*int bir deger alacagı için virgülden sonraki değerler etki etmez*/
			printf("The fifth digit  is:%d\n",fifth );
			number = number % 10000;/*diğer if kosulunada girebilsin diye sayının son 4 hanesi yeni sayı olur*/
		}
		if (number >= 1000 && number <= 9999)/*sayı buraya geldiginde kosul saglanıyorsa iceri girer*/
		{
			fourth = number / 1000;/*int bir deger alacagı için virgülden sonraki değerler etki etmez*/
			printf("The fourth digit  is:%d\n", fourth);
			number = number % 1000;/*diğer if kosulunada girebilsin diye sayının son 3 hanesi yeni sayı olur*/
		}
		if (number >= 100 && number <= 999)/*sayı buraya geldiginde kosul saglanıyorsa iceri girer*/
		{
			third = number / 100;/*int bir deger alacagı için virgülden sonraki değerler etki etmez*/
			printf("The third digit  is:%d\n",third );
			number = number % 100;/*diğer if kosulunada girebilsin diye sayının son 2 hanesi yeni sayı olur*/
		}
		if (number >= 23 && number <= 99)/*sayı buraya geldiginde kosul saglanıyorsa iceri girer*/
		{
			first = number % 10;/*sayının son hanesi alınacagı icin 10 a göre modunu aldım*/
			second = number / 10;/*int bir deger alacagı için virgülden sonraki değerler etki etmez*/
			printf("The second digit  is:%d\n", second );
			printf("The first digit is:%d\n", first);
		}

	}
	
	return 0;
}