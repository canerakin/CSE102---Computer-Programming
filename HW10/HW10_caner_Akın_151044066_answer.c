#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>/*bu kütüphanenin işlevi zamanı ölçmaktir*/

struct liste/*struct olarak bir liste tanımladım*/
{
	double n;
	struct liste *sonraki;/*sonraki eleman pointer olarak nitelendirildi*/
};
typedef struct liste x;

int asal_bulma(int sayi);/*gelen sayinin asal olup olmadığını kontrol eden fonksiyonu tanımladım*/
void file_scanf(double* array);/*dosyadan tüm sayıların okunacağı fonksiyonu tanımladım*/
int file_print_asal(double* array, double* array_asl ,int uzunluk);/*asal sayıları bulup klasöre yazma fonksiyonunu tanımladım*/
int file_link(double* array ,int uzunluk);/*asal sayıları birbirine bağlama fonksiyonunu tanımladım*/


int main()
{
	double *array;
	double *array_asl;
	double zaman_1 ,zaman_2 ,zaman_3 ;

	array = (double*)malloc(sizeof(double)*1000000);/*klasörden gelecek değerler için yer ayrılır*/
	array_asl = (double*)malloc(sizeof(double)*1000000);/*asal olan sayılar için yer ayrılır*/	
	
	file_scanf(array);/*dosyadan tüm sayıların okunacağı fonksiyonu çağırdım*/

	zaman_1 = file_print_asal(array ,array_asl , 1000000);/*500000 e kadar olan sayıların asal olanlarını bulma ve zamanını ölçer*/
	printf("1 ile 1000000  arasındaki asal sayıları bulup klasöre yazma süresi : %.2lf\n",zaman_1 );
/*
	zaman_2 = file_print_asal(array ,array_asl , 75000);
	printf("1 ile 75000 arasındaki asal sayıları bulup klasöre yazma süresi : %.2lf\n",zaman_2 );	

	zaman_3 = file_print_asal(array ,array_asl , 100000);	
	printf("1 ile 100000 arasındaki asal sayıları bulup klasöre yazma süresi : %.2lf\n",zaman_3 );
*/
	zaman_1 = file_link(array ,1000000);/*500000 e kadar olan sayılar arasında linked list ile birbirine bağlanmasını sağlar ve zamanını ölçer*/
	printf("1 ile 1000000 arasındaki sayıları birbirine bağlayıp klasöre yazma süresi : %.2lf\n",zaman_1 );
/*
	zaman_2 = file_link(array_asl ,75000);
	printf("1 ile 75000 arasındaki sayıları birbirine bağlayıp klasöre yazma süresi :%.2lf\n",zaman_2 );

	zaman_3 = file_link(array_asl ,100000);
	printf("1 ile 100000 arasındaki sayıları birbirine bağlayıp klasöre yazma süresi : %.2lf\n",zaman_3 );
*/
	free(array);/*sayıların olduğu bölge serbest bırakılır*/
	free(array_asl);/*asal sayıların olduğu bölge serbest bırakılır*/
	return 0;
}

int asal_bulma(int sayi)/*gelen sayinin asal olup olmadığını kontrol eden fonksiyon*/
{
	int count , i;
	count = 0;
	if (sayi == 1)/*sayinin 1 olma koşulunu yazdım*/
	{
		return 1;/*asal olmadığı için 1 döndürür*/
	}
	else if (sayi == 2)/*sayinin 2 olma koşulunu yazdım*/
	{
		return 0;/*asal oldugu için 0 döndürür*/
	}
	else
	{
		for (i = 1; i <= sayi / 2; ++i)/*sayının kaç tane böleni olduğu kontrol edilir*/
		{
			if (sayi % i == 0)/*tam bölense count artar*/
			{
				count += 1; 
			}
		}
		if (count == 1)
		{
			return 0;/*asal oldugu için 0 döndürür*/
		}
		else
		{
			return 1;/*asal olmadığı için 1 döndürür*/
		}
	}

}

void file_scanf(double* array)/*dosyadan tüm sayıların okunacağı fonksiyon*/
{
	FILE *file;/*dosya bir klasör olarak tanımlanır*/
	int i;
	double tam_sayi,bolum_kismi;

	file = fopen("data.txt","r"); /*dosya açma işlemi yapılır*/
	
	i = 0;
	while(i < 1000000)/*dosyadaki satır sayısı kadar ilerler*/
	{
		fscanf(file,"%lf,%lf",&tam_sayi,&bolum_kismi);/*dosyadan elemanlar satır satır alınır*/
		array[i] = tam_sayi + (bolum_kismi / 100);/*her satırda tam sayı olamsına rağmen double şeklinde yazıldığı için double şeklinde aldım*/
		i += 1;
	}
	fclose(file);/*dosyanın kapama işlemini gerçekleştirdim*/
	printf("Dosyadan okuma işlemi tamamlanmıştır.\n");
}

int file_print_asal(double* array , double* array_asl , int uzunluk)/*asal sayıları bulup klasöre yazma fonksiyonu*/
{
	FILE *open;/*dosya bir klasör olarak tanımlanır*/
	int i = 0 ,j = 0;
	int ret_degeri;
	double deger;
	time_t start,finish;/*zamanı bulmak için başlangıç ve bitiş zamanlarını tanımladım*/

	open = fopen("output_prime_dynamic_array.txt","w");/*dosya açma işlemi yapılır*/

	time(&start);/*başlangıç zamanı kayıt altında tutulur*/
	while(i < uzunluk)
	{
		ret_degeri = asal_bulma(array[i]);/*yaının asal olup olmadığını kontrol eden fonksiyona gönderilir*/
		if (ret_degeri == 0)/*return değerine göre sayı asal ise koşuldan içeri girer*/
		{
			array_asl[j] = array[i];/*sayı başka bir arraye kopyalanır*/
			fprintf(open,"%.2lf\n",array_asl[j]);/*dosyaya yazılır*/
			j += 1;
		}
		i += 1;
	}

	time(&finish);/*bitiş zamanı kayıt altında tutulur*/
	fprintf(open,"1 ile %d arasi asal sayi bulma süresi : %.2lf sn\n",uzunluk,difftime(finish,start));/*klasörün sonuna kaç saniye olduğu yazılır*/

	fclose(open);/*dosyanın kapama işlemini gerçekleştirdim*/
	return difftime(finish,start);
}

int file_link(double* array ,int uzunluk)/*asal sayıları birbirine bağlama fonksiyonu*/
{
	FILE *link;/*dosya bir klasör olarak tanımlanır*/
	x *etkin,*kuyruk; /*başlangıç ve bitiş noktalarını tanımladım*/
	int i = 0;
	int rtrn;

	time_t start,finish;/*zamanı bulmak için başlangıç ve bitiş zamanlarını tanımladım*/	

	link = fopen("output_prime_LiknedList.txt","w");
	time(&start);/*başlangıç zamanı kayıt altında tutulur*/

	etkin = (x*)malloc(sizeof(x));/*ilk elemana yer ayrılır*/
	kuyruk=etkin;
	while(i < uzunluk)/*gönderilen değere kadar olan asal sayılar birbirine bağlanır*/
	{
		rtrn = asal_bulma(array[i]);
		if (rtrn == 0)
		{
			kuyruk -> n = array[i];
			fprintf(link,"%.2lf\n",kuyruk -> n);/*pointerlanmış değer klasöre yazılır*/
			kuyruk -> sonraki = (x*)malloc(sizeof(x));/*her elemana ayrı olarak yer açılır*/
			kuyruk = kuyruk->sonraki; /*bir sonraki sayıya geçiş için*/
			kuyruk->sonraki=NULL;/*sonraki sayının yeri NULL oalrak atanır*/
		}
		i += 1;	
	}
	time(&finish);/*bitiş zamanı kayıt altında tutulur*/
	fprintf(link,"1 ile %d arasi linked list ile bağlama süresi : %.2lf sn\n",uzunluk,difftime(finish,start));/*klasörün sonuna kaç saniye olduğu yazılır*/
	fclose(link);/*dosyanın kapama işlemini gerçekleştirdim*/
	return difftime(finish,start);	
}