/*Caner AKIN
151044066*/
#include <stdio.h>/*standart input output kütüphanesi*/
#include <stdlib.h>/*random deger atamak için kullanılan kütüphane*/
#include <time.h>/*random deger atamak için kullanılan kütüphane*/
/*aşağıdaki fonksiyonlar ilk olarak tanımlanmış kısımlarıdır */
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();
void menu();

int main()
{
	srand(time(NULL)); /*random değer atama fonksiyonunu çağırır*/

	menu();/*diğer fonksiyonların bağlı olduğu ana fonksiyon menu fonksiyonu olduğu olduğu için main de sadece menu fonksiyonunu çağırdım*/
	return 0;
}

int getInt(int mini, int maxi)/*bu fonksiyon istenilen aralıkta bir değer girilene kadar sayı isteyen ve onu return eden bir fonksiyondur*/
{

	int flag , number;

	do
	{
		printf("Enter a number:");
		scanf("%d" ,&number);

		if (number >= mini && number <= maxi)
		{
			flag = 1; /*istenilen değer girildiği zaman flag 1 olur ve while döngüsünden çıkar */
		}
		else
		{
			printf("\nFalse enter\n");
			flag = 0;/*istenilen değer girilmezse flag değişmez ve döngü devam eder.*/
		}

	}while(flag == 0);/*istenilen değer girilmediği sürece döndürecek koşul*/

	return number;
}

int numberGeneratorBetweenRange(int min, int max)/*verilen iki sayı arasında random bir değer atayan fonksiyon*/
{
	int random , i;
	random  = 0 ;

	
	random = rand() % (max - min + 1);/*istanilen sayılar arasında olması için ilk başta random değeri min-max arası farka göre  modunu aldım*/
	random = random + min ;/*bu sayıya min ekleyince istenilen aralıkta bir değer atanır*/

	return random;
}

void horseRacingGame()/*at yarışının ana fonksiyonudur.işlemler ve döngüler burada gerçekleşir*/
{
	int horse_number , choise , i;
	int horse  , number1 = 20 , winner , number2 = 20  ; /*değerleri en yükseğe atadımki hızlı koşan at en yüksek değerlere göre değerlensin*/

	horse_number = numberGeneratorBetweenRange( 3 , 5); /*at sayısı random bir değişken olarak 3 ile 5 arasında atanır*/
	printf("\nNumber of Horse:%d\n", horse_number);
	choise = getInt( 1 , horse_number); /*random atanan at sayısına göre 1 den atanan atlar arasından birini seçmeniz için atanır*/
	printf("\nHorse Number:%d", choise);
	printf("\nRacing starts...\n");



	for (i = 1; i <= horse_number; ++i)/*ne kadar sayıda at varsa onlara değer atar ve karşılaştırır */
	{
		horse = 0;
		horse = numberGeneratorBetweenRange(10 , 20); /*ata random bir süre atar.bu süre yarışı tamamlama süresidir*/
		printf("Horse%d: %d\n",i , horse);
		
		if (horse < number1 ) /*eğer sıradaki at en hızlı ise buraya girer*/
		{
			if (number1 <= number2)/*bu durumda artık ikinci at eski bir numara olur*/
			{
				number2 = number1;
			}
			number1 = horse ; /*1. atın number1 diye atanması*/
			winner = i ;/*birinci atın sırası kayıt altına alınır*/
			
		}
		else if (horse == number1)/*sıradaki at en hızlı ile eşit ise buraya girer*/
		{
			number2 = number1; /*bu durumda en hızlı iki at birbirine eşit olmalıdır bu yüzden number1 ile number2 yi birbirine eşitledim*/
			winner = i ;/*her ihtimale karşı yinede 1. olan atın sıralaması kayıt altında tutulur.*/
		}

	}

	if (number1 == number2) /*eğer ilk iki at eşit sürede bitirmiş ise kazanan yoktur*/
	{
		printf("You lose.Winner is horse %d.\n\n", winner );
	}
	else if(winner == choise) /*eğer kazananı bilirseniz kazandığınız yazar*/
	{
		printf("You win!\n\n");

	}else if (winner != choise)/*eğer kazanan bilimezse ekrana kaybedildiği ve kazanan yazar*/
	{
		printf("You lose.Winner is horse %d.\n\n", winner );
	}

}

void countOccurrence()/*verilen küçük sayının büyük sayının içinde kaç tane harf olduğunu bulan fonsiyondur*/
{
 	int big_number , search_number , occurrence ,big_number2 ;
 	

 	printf("\nenter a big number:");/*büyük numara kullanıcıdan alınır*/
 	scanf("%d" , &big_number);
 	printf("enter a search number:");/*aranacak numarada kullanıcıdan alınır*/
 	scanf("%d" ,&search_number);

 	big_number2 = big_number;/*big number üzerinde yapılacak olan değişimler için big_number_2 yedek olarak elde tutulur*/
 	
 	while(big_number >= search_number && big_number <= 9999999999 ) /*büyük sayı aranan sayıdan küçük olana kadar devam eden while döngüsü*/
 	{
 		if (search_number == 0)
 		{
 			if (big_number <= 9)
 			{
 				big_number = -1;
 			}
 			else if (big_number % 10 == 0) /*son hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			
 		}

 		else if (search_number > 0 && search_number <= 9)/*search number tek haneli ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 10 == 0) /*son hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda aynı sayı oldukları için sayac 1 artar*/
 			} 
 		}

 		else if (search_number >= 10 && search_number <= 99) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 100 == 0)/*son 2 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 100 && search_number <= 999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 1000 == 0)/*son 3 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 1000 && search_number <= 9999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 10000 == 0)/*son 4 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 10000 && search_number <= 99999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 100000 == 0)/*son 5 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 100000 && search_number <= 999999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 1000000 == 0)/*son 6 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 1000000 && search_number <= 9999999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 10000000 == 0)/*son 7 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 10000000 && search_number <= 99999999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 100000000 == 0)/*son 8 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 100000000 && search_number <= 999999999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 1000000000 == 0)/*son 9 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}
 		else if (search_number >= 1000000000 && search_number <= 9999999999) /*search number iki haneli bir sayı ise buraya girer*/
 		{
 			big_number = big_number - search_number;
 			if (big_number % 10000000000 == 0)/*son 10 hanesi 0 ise son basamak aynı sayıdır demek olur*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			}
 			else if (big_number == 0)/*search number çıkarıldığı zaman sayı 0 oluyorsa search ile aynı sayıdır*/
 			{
 				occurrence = occurrence + 1;/*bu durumda sayac 1 artar*/
 			} 
 			
 		}

 		if (big_number != -1)
 		{
 			big_number2 = big_number2 / 10;  /*big number her seferinde 1 basamak sola kayar*/
 			big_number = big_number2;        /*big number üzerinde uygulanan işlemlerin etkisi bu sayede kalkar*/
 		}
 		 
 				

 	}
 	printf("Occurrence:%d\n\n", occurrence);/*sayac ekrana yazılır*/


}

void triangleOfSequences()/*1 den başlayarak random atanan değere kadar sayının 1 katından başlayarak artan  ve böyle sırayla artarak karesine kadar giden ve akrana yazan fonksiyondur. */
{
	int number , loop_number , i , j , total;

	loop_number = numberGeneratorBetweenRange( 2 , 10);/*2 ile 10 arasında random bir sayı üretmesi için fonksiyonu atadım*/

	for (i = 1; i <= loop_number; ++i)/*random atanan değer kadar dönen bir for döngüsü açtım*/
	{
		total = 0;
		for (j = 1; j <= i; ++j)/*sayının kendisi kadar dönen bir for döngüsü*/
		{
			total = total + i ; /*döngü devam ederken sırayla sayının 1 katı 2 katı ve karesi ekrana yazılana kadar devam eder*/
			printf("%d ", total);
		}		
		printf("\n");
	}

}

void menu()/*oyunların secip çağırıldığı fonksiyondur*/
{
	int choise;

	do/*ilk olarak direk döngüye girer*/
	{
		printf("1. Horse Racing Game\n2. Occurrence Counter\n3. Triangle of Sequences\n0. Exit\n");
		printf("Enter a choise:");
		scanf("%d" , &choise);/*yanlış girilen her döngüde tekrardan choise istenir*/

		switch(choise)/*seçilen oyunun çağırımına göre secimlere dağılır*/
		{
			case 1: /*1. oynu oynamak isteyen burayı seçer */
				printf("\n1. Horse Racing Game\n");
				horseRacingGame();/*at yarışı oyunu fonksiyonu çağırılır*/
				break;
			case 2: /*2. oynu oynamak isteyen burayı seçer */
				printf("\n2. Occurrence Counter\n");
				countOccurrence();
				break;
			case 3: /*3. oynu oynamak isteyen burayı seçer */
				printf("\n3. Triangle of Sequences\n");
				triangleOfSequences();
				break;
			default : /*istenilen değerler dışında bir girdi olursa buraya girer*/
				if (choise != 0) /*yanlış bir girdi girildiğini ekrana yazar*/
				{
					printf("\nFalse choise\n\n");
				}	
				break;
		}

	}while(choise != 0);

}