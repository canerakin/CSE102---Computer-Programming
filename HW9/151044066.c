#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{sol ,sag ,yukari ,asagi}yonler;/*random olarak atanan yönlerin enum olarak tanımladım*/
typedef struct/*haritanın bileşenlerinin struct olarak tanımlamasını yaptım*/
{
	char **Map;
	int Width;
	int Height;
	int Flower_X;
	int Flower_Y;
}Forest;

typedef struct /*botanikçinin özelliklerini struct olarak tanımladım*/
{
	int Coord_X;
	int Coord_Y;
	int Water_Bottle_Size;
}Botanist;

void init_game (Forest *forest, Botanist *botanist);/*tabloyu klasörden okuma ve gerkli atamaları yapan fonksiyonu tanımladım*/
void print_map (Forest *forest);/*tabloyu ekrana basan fonksiyonu tanımladım*/
void search (Forest *forest, Botanist *botanist);/*oyunun oynandığı fonksiyonu tanımladım*/

int main()
{
	Forest forest;/*Forest tipinde forest değişkeni tanımladım*/
	Botanist botanist;/*Botanist tipinde botanist tanımladım*/

	srand(time(NULL));/*rastkele sayı üretmek için fonksiyonu kullandım*/

	init_game (&forest ,&botanist);/*atama fonksiyonunu çağırdım*/
	print_map(&forest);/*yazma fonksiyonunu çağırdım*/
	search(&forest,&botanist);/*oynama fonksiyonunu çağırdım*/

	return 0;
}

void init_game (Forest *forest, Botanist *botanist)/*tabloyu klasörden okuma ve gerkli atamaları yapan fonksiyon*/
{
	FILE *open;/*klasörü atamak için değişken oluşturdum*/
	int i = -2;
	int j;
	int ml;
	char array[10][12];	
	open = fopen("init.csv","r"); /*klasörü okumak için açtım*/

while(i<10)/*dosyadaki tüm verileri okuyana kadar döner*/
	{
		if (i == -2)/*ilk satırdaki değer için*/
		{
			fscanf(open,"%d",&botanist -> Water_Bottle_Size);/*dosyadan veri alınır*/
		}
		else if (i == -1)/*ikinci satırdaki değer için*/
		{
			fscanf(open,"%d,%d",&forest -> Width,&forest -> Height);/*dosyadan veriler alınır*/

			forest -> Map = (char**)calloc(forest -> Height,sizeof(int*));/*gerekli değerler geldiği için yer ayrılyılabilir*/
			for (j = 0; j < forest -> Width; ++j)
			{
				forest -> Map[j] = (char*)calloc(forest -> Width,sizeof(int));/*gerekli değerler geldiği için yer ayrılyılabilir*/
			}

		}
		else if (i >= 0)/*tablonun değerleri burada alınır*/
		{	
			for (j = 0; j < 12; ++j)
			{			
				fscanf(open,"%c,",&array[i][j]);/*dosyadan veri alınır*/
			}
		} 

		i += 1;
	}

	for (i = 0; i < 10; ++i)
	{
		for (j = 2; j < 12; ++j)
		{
			forest -> Map[i][j-2] = array[i][j];/*alınan veriler gerekli atamalar ile yerleştirilir ve başlangıç bitiş noktası bulunur*/
			if (array[i][j] == 'B')/*başlangıç noktası*/
			{
				botanist -> Coord_X = i;
				botanist -> Coord_Y = j - 2;
			}
			if (array[i][j] == 'F')/*bitiş noktası*/
			{
				forest -> Flower_X = i;
				forest -> Flower_Y = j - 2;
			}
		}
	}
	fclose(open);/*klasörü kapattım*/
}

void print_map (Forest *forest)/*tabloyu ekrana basan fonksiyon*/
{
	int i,j;

	for (i = 0;i < forest -> Height; ++i)/*haritanın satırlarını temsil eder*/
	{
		for (j = 0; j < forest -> Width; ++j)/*haritanın sütunlarını temsil eder*/
		{
			printf("%c",forest -> Map[i][j]);	/*tüm karakterler tek tek ekrana yazılır*/
		}
		printf("\n");
	}
	printf("\n");

}

void search (Forest *forest, Botanist *botanist)/*oyunun oynandığı fonksiyon*/
{
	int yon;
	yon = rand() % 4;/*rastkele değer atanır*/

	if (botanist -> Coord_X == forest -> Flower_X && botanist -> Coord_Y == forest -> Flower_Y)/*botanistin olduğu yer çiçeğin olduğu yer ise program biter*/
	{
		forest -> Map[botanist -> Coord_X][botanist -> Coord_Y] = ' ';
		printf("\nI have found it on (%d,%d)!",botanist -> Coord_X ,botanist -> Coord_Y);
	}
	else if (botanist -> Water_Bottle_Size == 0)/*botanistin suyu biter ise yardım çağırır ve program biter*/
	{
		printf("\nHelp! I am on (%d,%d)",botanist -> Coord_X ,botanist -> Coord_Y);
	}
	else/*eğer oyun devem edecek ise bu koşula girer*/
	{
		printf("\n");
		if (yon == sol && botanist -> Coord_Y > 0 && forest -> Map[botanist -> Coord_X][botanist -> Coord_Y - 1] != '#')/*sola doğru hareket etme koşulları uyarsa uygular*/
		{
			forest -> Map[botanist -> Coord_X][botanist -> Coord_Y - 1] = 'B';/*gideceği yer atanır*/
			forest -> Map[botanist -> Coord_X][botanist -> Coord_Y] = ' ';/*eski yeri boş olarak atanır*/
			botanist -> Coord_Y -= 1;/*kordinatı güncellenir*/
			botanist -> Water_Bottle_Size -= 1;/*suyu güncellenir*/
			printf("Searching...\n\n");
			print_map(forest);/*son hali tabloya basılır*/		
			search(forest,botanist);/*yeni bir hareket için fonksiyon tekrardan çağırılır*/
		}
		else if (yon == sag && botanist -> Coord_Y < 9 && forest -> Map[botanist -> Coord_X][botanist -> Coord_Y + 1] != '#')/*sağa doğru hareket etme koşulları uyarsa uygular*/
		{
			forest -> Map[botanist -> Coord_X][botanist -> Coord_Y + 1] = 'B';/*gideceği yer atanır*/
			forest -> Map[botanist -> Coord_X][botanist -> Coord_Y] = ' ';/*eski yeri boş olarak atanır*/			
			botanist -> Coord_Y += 1;/*kordinatı güncellenir*/
			botanist -> Water_Bottle_Size -= 1;/*suyu güncellenir*/
			printf("Searching...\n\n");			
			print_map(forest);/*son hali tabloya basılır*/
			search (forest,botanist);/*yeni bir hareket için fonksiyon tekrardan çağırılır*/
		}
		else if (yon == yukari && botanist -> Coord_X > 0 && forest -> Map[botanist -> Coord_X - 1][botanist -> Coord_Y] != '#')/*yukar doğru hareket etme koşulları uyarsa uygular*/
		{
			forest -> Map[botanist -> Coord_X - 1][botanist -> Coord_Y] = 'B';/*gideceği yer atanır*/
			forest -> Map[botanist -> Coord_X][botanist -> Coord_Y] = ' ';/*eski yeri boş olarak atanır*/
			botanist -> Coord_X -= 1;/*kordinatı güncellenir*/
			botanist -> Water_Bottle_Size -= 1;/*suyu güncellenir*/
			printf("Searching...\n\n");
			print_map(forest);/*son hali tabloya basılır*/
			search (forest,botanist);/*yeni bir hareket için fonksiyon tekrardan çağırılır*/
		}
		else if (yon == asagi && botanist -> Coord_X < 9 && forest -> Map[botanist -> Coord_X + 1][botanist -> Coord_Y] != '#')/*aşağı doğru hareket etme koşulları uyarsa uygular*/
		{
			forest -> Map[botanist -> Coord_X + 1][botanist -> Coord_Y] = 'B';/*gideceği yer atanır*/
			forest -> Map[botanist -> Coord_X][botanist -> Coord_Y] = ' ';/*eski yeri boş olarak atanır*/			
			botanist -> Coord_X += 1;/*kordinatı güncellenir*/
			botanist -> Water_Bottle_Size -= 1;/*suyu güncellenir*/
			printf("Searching...\n\n");	
			print_map(forest);/*son hali tabloya basılır*/
			search (forest,botanist);/*yeni bir hareket için fonksiyon tekrardan çağırılır*/
		}	
		else
		{
			search (forest,botanist);/*zarın koşuluna uymaz ise tekrar zar atacak şekilde tekrar fonksiyon çağırılır*/
		}	
	}

}