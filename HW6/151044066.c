#include <stdio.h>
#define ASCII_FARK 26 /*karakterler arası key kullanarak fark kullanılırken farkı 26 olarak tanımladım*/
#define MAX 1024 /*arrayin alabileceği en yüksek uzunluğu tanımladım*/
void menu();
int find_size_of_line(char line[]);/*uzunluğu bulan fonksiyonu tanımladım*/
void reverse_line(char line[], int line_lenght);/*cümleyi terse çeviren fonksiyonu tanımladım*/
void encrypt_open_msg();/*dosya1 i dosya2 ye şifreli olarak gönderen fonksiyonu tanımladım*/
void decrypt_secret_msg();/*dosya2 yi dosya1 e şifresini çözüp gönderen fonksiyonu tanımladım*/

int main()/*ana fonksiyon*/
{
	menu();/*menu fonksiyonunu çağırdım*/
	return 0;
}


void menu()/*kullanıcıdan seçenekleri isteyen fonsiyondur*/
{
	char secim;

	do/*secim bir değere sahip olmamasına rağmen do-while direk girer*/
	{
		printf("\n1. Encrypt\n2. Decrypt\n0. Exit");
		printf("\nsecim yapiniz: ");/*kullanıcıdan secim yapmasını istedim*/
		scanf(" %c",&secim);

		switch(secim)/*kullanıcının girdiği değer switch-case sayesinde bölümlere ayrılır*/
			{

				case '1':/*kullanıcı 1 değerini girerse 1. secenege girer*/
					encrypt_open_msg();
					break;
				case '2':	/*kullanıcı 2 değerini girerse 2. secenege girer*/
					decrypt_secret_msg();
					break;
				case '0':	/*kullanıcı 0 değerini girerse çıkış yapılacapı bildirisini verir*/
					printf("cıkıs yaptınız\n");
					break;	
				default :	/*menüdeki değerler dışında bir değer veya karakter girildiği zaman buraya girer ve tekrar seçim için ekrana döner*/
					printf("Yanlis deger girdiniz\n");
					break;
			}

	}while(secim != '0');/*0 olduğunda döngüden çıkar*/
}

void encrypt_open_msg()/*bu fonksiyon çağırıldığı zaman birinci dosyadaki bilgiyi ters çevirerek ve şifreleyerek dosya2 ye aktarır */
{
	FILE * dosya;/*dosya1 için klasör tanımlama*/
	FILE * dosya_2;/*dosya2 için klasör tenımlama*/
	int i = 0;
	char sifre[MAX];/*dosyanın üzerine yazılacağı arrayi tanımladım*/
    char harf;
    int uzunluk,key;

	dosya = fopen("open_msg.txt","r");/*dosya1 çağırılır*/
	dosya_2 = fopen("secret_msg.txt","w");/*dosya2 çağırılır*/

	while(!feof(dosya))/*dosyadaki taranmamış eleman kalmayana kadar devam eder*/
	{
		fscanf(dosya,"%c",&harf);/*dosyadan harf olarak teker teker alınır*/
		sifre[i]=harf;/*arraye dosyadaki bilgiler atanır*/
		i += 1;
	}
	printf("\n%s",sifre );/*dosyadan alınan bilgiler ekrana yazılır*/

	uzunluk = find_size_of_line(sifre);/*bilgilerin yani arrayin uzunluğunu buluruz*/
	reverse_line(sifre ,uzunluk);/*cümleler tersine dönmesi için çağırıldı*/

	i = 0;
	printf("key degerini girdiniz: ");
	scanf("%d",&key);
	printf("\n");
	while(sifre[i] != '\0')/*arrayin son elemanına kadar devam eder*/
	{
		if (sifre[i] == '\n')/*bu karakter üzerinde değişiklik yapılmaz*/
		{
		}
		else if (sifre[i] == ' ')/*boşluk karakterinin dönüşümü*/
		{
			sifre[i] = '_';
		}
		else if (sifre[i] == '.')/*nokta karakterinin değişimi*/
		{
			sifre[i] = '*';
		}
		else if ((sifre[i] - key) >= 'a' && sifre[i] <= 'z')/*normal bir şekilde fark alınabiliyorsa buraya girer*/
		{
			sifre[i] = sifre[i] - key;
		}
		else if ((sifre[i] - key) < 'a' && sifre[i] <= 'z')/*eğer key sayının a ile farkından büyükse buradaki işlemler uygulanır*/
		{
			sifre[i] = sifre[i] - key + ASCII_FARK;
		}
		i += 1;
	}
	printf("%s\n",sifre);/*şifrelenmiş metin ekrana yazılır*/

	i = 0;
	while(sifre[i] != '\0')/*şifrelenmiş metni dosya2 ye gönderir*/
	{
		fprintf(dosya_2,"%c",sifre[i]);/*her karakter teker teker dosya2 ye işlenir*/
		i += 1;
	}

	fclose(dosya_2);/*dosya2 kapanış*/
	fclose(dosya);/*dosya1 kapanış*/
}

void decrypt_secret_msg()/*bu fonksiyon çağırıldığı zaman ikinci dosyadaki bilgiyi ters çevirerek ve şifreyi çözerek dosya1 e aktarır */
{
	FILE * dosya;/*dosya1 için klasör tenımlama*/
	FILE * dosya_2;/*dosya2 için klasör tenımlama*/
	int i = 0;
	char sifre[MAX];/*dosyanın üzerine yazılacağı arrayi tanımladım*/
    char harf;
    int uzunluk,key;

	dosya = fopen("secret_msg.txt","r");/*dosya2 çağırılır*/
	dosya_2 = fopen("open_msg.txt","w");/*dosya1 çağırılır*/

	while(!feof(dosya))/*dosyadaki taranmamış eleman kalmayana kadar devam eder*/
	{
		fscanf(dosya,"%c",&harf);/*dosyadan harf olarak teker teker alınır*/
		sifre[i]=harf;/*arraye dosyadaki bilgiler atanır*/
		if(sifre[i]=='\n'){

		}
		i += 1;
	}
	sifre[i-1] = '\0';
	printf("\n%s",sifre );/*dosyadan alınan bilgiler ekrana yazılır*/

	i = 0;
	printf("key degerini girdiniz: ");
	scanf("%d",&key);
	while(sifre[i] != '\0')/*arrayin son elemanına kadar devam eder*/
	{
		if (sifre[i] == '\n')/*bu karakter üzerinde değişiklik yapılmaz*/
		{
		}
		else if (sifre[i] == '_')/*altre karakterinin dönüşümü*/
		{
			sifre[i] = ' ';
		}
		else if (sifre[i] == '*')/*yıldız karakterinin dönüşümü*/
		{
			sifre[i] = '.';
		}
		else if ((sifre[i] + key) <= 'z' && sifre[i] >= 'a')/*normal bir şekilde fark alınabiliyorsa buraya girer*/
		{
			sifre[i] = sifre[i] + key;
		}
		else if ((sifre[i] + key) > 'z' && sifre[i] >= 'a')/*eğer key sayının z ile farkından büyükse buradaki işlemler uygulanır*/
		{
			sifre[i] = sifre[i] + key - ASCII_FARK;
		}
		i += 1;
	}
	printf("%s\n",sifre);/*şifrelenmiş metin ekrana yazılır*/

	uzunluk = find_size_of_line(sifre);/*bilgilerin yani arrayin uzunluğunu buluruz*/
	reverse_line(sifre ,uzunluk);/*ters olan arrayin düz şekle çevirilmesi*/

	printf("\n%s\n",sifre );/*şifresi çözülmüş metin ekrana yazılır*/
  
	i = 0;
	while(sifre[i] != '\0')/*şifrelenmiş metni dosya2 ye gönderir*/
	{
		fprintf(dosya_2,"%c",sifre[i]);/*her karakter teker teker dosya2 ye işlenir*/
		i += 1;
	}

	fclose(dosya_2);/*dosya2 kapanış*/
	fclose(dosya);/*dosya1 kapanış*/
}

int find_size_of_line(char line[])/*gelen karakter arrayinin uzunluğunu bulan fonksiyondur*/
{
	int count = 0 ,i = 0;
	while(line[i] != '\0')/*son elemana kadar devam eder*/
	{
		if (line[i] != '\n')/*boşluk karakterini dahil etmemek için*/
		{
			count += 1;
		}
		i += 1;
	}

	return count - 2;
}

void reverse_line(char line[], int line_lenght)/*gelen karakter arrayindeki cümlelerin tersine çevirilmesini sağlar*/
{
	int i = 0 ,j = 0,x = 0;
	char yedek[MAX];

	while(line[i] != '\0')/*son elemana kadar devam eder*/
	{	
		j = i;
		while((line[j] >= 'a' && line[j] <= 'z') || line[j] == ' ' || line[j] == '.') /*cümlenin kopyasını çıkarmak için cümle sınır koşullarıdır*/
		{
			yedek[j] = line[j];
			j += 1;
		}
		yedek[j] = '\n';/*cümle sonunu belli etmek için kullandım*/
		j -= 1;
		
		while((line[i] >= 'a' && line[i] <= 'z') || line[i] == ' ' || line[i] == '.')/*cümlenin tersine çevirilmesi için gereken atamalar*/
		{
			line[i] = yedek[j];
			i += 1;
			j -= 1;
		}
		i += 1;
	}
}