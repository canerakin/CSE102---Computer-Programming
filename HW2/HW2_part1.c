/*Caner AKIN
151044066*/
#include <stdio.h>/*standart input output kütüphanesi*/
#include <stdlib.h>/*rastkele değer atama kütüphanesi*/
#include <time.h>/*rastkele deger atama kütüphanesi*/

int main()
{
	int kisi_sayisi ,make_selection ,r , i;
	int en_basarili = 0,en_basarisiz = 100 ;
	double ortalama = 0 ;
	int harf_notu_a = 0,harf_notu_b = 0 ,harf_notu_c = 0,harf_notu_d = 0,harf_notu_f = 0;
	int index1 = 0 ,index2 = 0;
	char harf_notu_kucuk ,harf_notu_buyuk;

	kisi_sayisi = 2;/*while döngüsüne girebilsin diye ilk olarak 2 atadım*/
	make_selection = 0;/*while döngüsüne girebilsin diye ilk asta 0 atadım*/
	srand(40);

	while(kisi_sayisi > 50 || kisi_sayisi <3)/*istenilen degeri vermezse sürekli yeni sayı ister*/
	{
		printf("Enter student count:");
		scanf("%d" ,&kisi_sayisi);
		if (kisi_sayisi > 50 || kisi_sayisi <3)/*istenilen degeri vermezse tekrar tekrar ister*/
		{
			printf("\nNot in Range!!!\n");
		}
	}
	for (i = 1; i <= kisi_sayisi; ++i)/*kisi sayısına kadar gidecek for döngüsü*/
	{
		r = rand() % 101 ;/*0 ile 100 arsındaki notları atamak için kullandım*/
		printf("%d  ", r );
		if (en_basarili < r)/*yeni acıklana not eski basarılıdan yüksekse yeni basarılı not o olur*/
		{
			en_basarili = r;
			index1 = i;
			if ( r <= 59)/*harf notunu belirler*/
			{
				harf_notu_buyuk = 'F';
			}
			else if (r >= 60 && r <=69)/*harf notunu belirler*/
			{
				harf_notu_buyuk = 'D';
			}
			else if (r >= 70 && r <=79)/*harf notunu belirler*/
			{
				harf_notu_buyuk = 'C';
			}
			else if (r >= 80 && r <=89)/*harf notunu belirler*/
			{
				harf_notu_buyuk = 'B';
			}
			else if (r >= 90)/*harf notunu belirler*/
			{
				harf_notu_buyuk = 'A';
			}

		}
		else if (en_basarisiz > r)/*yeni acıklana not eski basarısızdan yüksekse yeni basarısız not o olur*/
		{
			en_basarisiz = r;
			index2 = i;
				if ( r <= 59)/*harf notunu belirler*/
				{
					harf_notu_kucuk = 'F';
				}
				else if (r >= 60 && r <=69)/*harf notunu belirler*/
				{
					harf_notu_kucuk = 'D';
				}
				else if (r >= 70 && r <=79)/*harf notunu belirler*/
				{
					harf_notu_kucuk = 'C';
				}
				else if (r >= 80 && r <=89)/*harf notunu belirler*/
				{
					harf_notu_kucuk = 'B';
				}
				else if (r >= 90)/*harf notunu belirler*/
				{
					harf_notu_kucuk = 'A';
				}
		
		}

		if ( r <= 59)/*harf notunun sayısını belirler*/
		{
			harf_notu_f = harf_notu_f + 1;
		}
		else if (r >= 60 && r <=69)/*harf notunun sayısını belirler*/
		{
			harf_notu_d = harf_notu_d + 1;
		}
		else if (r >= 70 && r <=79)/*harf notunun sayısını belirler*/
		{
			harf_notu_c = harf_notu_c + 1;
		}
		else if (r >= 80 && r <=89)/*harf notunun sayısını belirler*/
		{
			harf_notu_b = harf_notu_b + 1;
		}
		else if (r >= 90)/*harf notunun sayısını belirler*/
		{
			harf_notu_a = harf_notu_a + 1;
		}

		ortalama = ortalama + r;/*tüm notların toplamı burada toplanır*/
	}

	ortalama = ortalama / kisi_sayisi;/*toplam notlar kisi sayısına bölünerek ortalama bulunur*/

	while(make_selection != -1)/*-1 olmadığı sürece dönen bir while döngüsü*/
	{
		printf("\nStudent Score Calculate Menu for %d Student\n", kisi_sayisi );/*menü ekrana yazılır*/
		printf("1) Most Successful Student\n");
		printf("2) Most Unsuccessful Student\n");
		printf("3) Letter Grade Statistics\n");
		printf("4) Calculate Average\n");
		printf("5) Show all Data\n");

		printf("\t\tMake Selection:");/*menüden bir sık secimi istenir*/
		scanf("%d",&make_selection);

		if (make_selection != -1)/*kullanıcının -1 dısındaki tün degerleri içeri girer*/
		{
			switch (make_selection)/*secimin ne olduguna göre durumların ekrana yazımı kısmıdır*/
			{
				case 1:	/*1. şık secildiğinde bu değerler ekrana yazılır*/
					printf("Most Successful Student:\n");
					printf("Index:%d\n",index1);
					printf("Score:%d\n",en_basarili );
					printf("Letter grade: %c\n\n",harf_notu_buyuk);
					break;
					
				case 2:/*2. şık secildiğinde bu değerler ekrana yazılır*/
					printf("Most Unsuccessful Student:\n");
					printf("Index:%d\n",index2);
					printf("Score:%d\n",en_basarisiz );
					printf("Letter grade: %c\n\n",harf_notu_kucuk);
					break;

				case 3:/*3. şık secildiğinde bu değerler ekrana yazılır*/
					printf("%d student got letter 'A'\n",harf_notu_a );
					printf("%d student got letter 'B'\n", harf_notu_b);
					printf("%d student got letter 'C'\n",harf_notu_c );
					printf("%d student got letter 'D'\n", harf_notu_d);
					printf("%d student got letter 'F'\n\n", harf_notu_f);
					break;

				case 4:/*4. şık secildiğinde bu değerler ekrana yazılır*/
					printf("The average Score of %d Student is %.2lf\n\n", kisi_sayisi , ortalama);
					break;

				case 5:/*5. şık secildiğinde bu değerler ekrana yazılır*/
					printf("Most Successful Student:\n");
					printf("Index:%d\n",index1);
					printf("Score:%d\n",en_basarili );
					printf("Letter grade: %c\n\n",harf_notu_buyuk);

					printf("Most Unsuccessful Student:\n");
					printf("Index:%d\n",index2);
					printf("Score:%d\n",en_basarisiz );
					printf("Letter grade: %c\n\n",harf_notu_kucuk);

					printf("%d student got letter 'A'\n",harf_notu_a );
					printf("%d student got letter 'B'\n", harf_notu_b);
					printf("%d student got letter 'C'\n",harf_notu_c );
					printf("%d student got letter 'D'\n", harf_notu_d);
					printf("%d student got letter 'F'\n\n", harf_notu_f);

					printf("The average Score of %d Student is %.2lf\n\n", kisi_sayisi , ortalama);
					break;

				default :/*kullanıcı secim yaparken istenilen değerleri girmezse bu kısmı seçilmiş olur*/
					printf("\nFalse Selection!!!");
					break;
					
			}
		}

	}

	return 0;
}
