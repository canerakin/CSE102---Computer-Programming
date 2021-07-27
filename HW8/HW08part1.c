#include <stdio.h>/*standar input output kütüphanesini çağırdım*/
#include <stdlib.h>/*random sayı atamak için gerekli bir kütüphaneyi çağırdım*/
#include <time.h>/*random sayı atamak için gerekli bir kütüphaneyi çağırdım*/

typedef struct /*struct olarak tanımlamaları yaptım*/
{
	char *text;
	char type;
	int data;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

void write_board(block board[][10]);/*atamaları yapıp ekrana yazacak olan fonksiyonu çağırdım*/
int removal(block board[][10] ,int x ,int y ,int count ,int steps);/*hareket edecek olan ve kaç hamlede bittiğini sayan fonksiyonu tanımladım*/
void single_player(block board[][10]);
void multiplayer(block board[][10]);

int main()
{
	srand(time(NULL));
	block board[10][10];/*struct tipinde bir array tanımladım*/

	write_board(board);/*atamaları yapıp ekrana yazacak olan fonksiyonu çağırdım*/
	single_player(board);/*tek kişilik bir oyun oynayacak olan fonksiyonu çağırdım*/
	multiplayer(board);/*multiplayer olarak iki kişilik oyun oynatacak ve kazananı belirleyecek olan fonksiyonu çağırdım*/

	return 0;
}

void write_board(block board[][10])/*atamaları yapıp ekrana yazacak olan fonksiyon burada işleme geçer*/
{
	int i,j,number=1;

	for (i = 9; i >= 0; --i)/*tahtadaki sayıları olması gerektiği gibi sıraladım*/
	{
		if (i % 2 == 1)/*tek satırlar kendi özelliğine göre ayrılır*/
		{
			for (j = 9; j >= 0; --j)
			{
				board[i][j].data = number;
				number += 1;
			}
		}
		else/*çift satırlar kendi özelliğine göre ayrılır*/
		{
			for (j = 0; j < 10; ++j)
			{
				board[i][j].data = number;
				number += 1;
			}			
		}
	}

	for (i = 0; i < 10; ++i)/*tahtanın heryerine karakter atadım*/
	{
		for (j = 0; j < 10; ++j)
		{
			board[i][j].text = "a";
		}
	}

	for (i = 0; i < 10; ++i)/*tahtanın kordinatlarını bulunacak yere göre atadım*/
	{
		for (j = 0; j < 10; ++j)
		{
			board[i][j].pos_x = i;
			board[i][j].pos_y = j;
		}
	}	
/*Burada tahta üzerinde sayı değilde karakter olan kutuların printf atamalarını yaptım*/
	board[9][9].text = "1(start)";/*atamayı gerçekleştirdim*/
	board[9][4].text = "S{1}";/*atamayı gerçekleştirdim*/
	board[9][3].text = "M{11}";/*atamayı gerçekleştirdim*/
	board[8][6].text = "M{28}";/*atamayı gerçekleştirdim*/
	board[8][2].text = "P";/*atamayı gerçekleştirdim*/
	board[7][5].text = "S{12}";/*atamayı gerçekleştirdim*/
	board[7][1].text = "B";/*atamayı gerçekleştirdim*/
	board[6][9].text = "T";/*atamayı gerçekleştirdim*/
	board[6][5].text = "B";/*atamayı gerçekleştirdim*/
	board[6][1].text = "M{52}";/*atamayı gerçekleştirdim*/
	board[5][5].text = "S{22}";/*atamayı gerçekleştirdim*/
	board[5][2].text = "P";/*atamayı gerçekleştirdim*/
	board[5][0].text = "B";/*atamayı gerçekleştirdim*/
	board[4][9].text = "S{44}";/*atamayı gerçekleştirdim*/
	board[4][6].text = "M{77}";/*atamayı gerçekleştirdim*/
	board[4][3].text = "T";/*atamayı gerçekleştirdim*/
	board[3][7].text = "S{52}";/*atamayı gerçekleştirdim*/
	board[3][4].text = "B";/*atamayı gerçekleştirdim*/
	board[3][1].text = "M{77}";/*atamayı gerçekleştirdim*/
	board[2][8].text = "T";/*atamayı gerçekleştirdim*/
	board[2][5].text = "M{83}";/*atamayı gerçekleştirdim*/
	board[2][2].text = "S{68}";/*atamayı gerçekleştirdim*/
	board[1][8].text = "B";/*atamayı gerçekleştirdim*/
	board[1][5].text = "P";/*atamayı gerçekleştirdim*/
	board[1][1].text = "M{94}";/*atamayı gerçekleştirdim*/
	board[0][8].text = "S{56}";/*atamayı gerçekleştirdim*/
	board[0][7].text = "S{72}";/*atamayı gerçekleştirdim*/
	board[0][2].text = "T";	/*atamayı gerçekleştirdim*/
	board[0][9].text = "100(Finish)";/*atamayı gerçekleştirdim*/

/*Burada tahta üzerinde sayı değilde karakter olan kutuların tür atamalarını yaptım*/
	board[9][4].type = 'S';/*atamayı gerçekleştirdim*/
	board[9][3].type = 'M';/*atamayı gerçekleştirdim*/
	board[8][6].type = 'M';/*atamayı gerçekleştirdim*/
	board[8][2].type = 'P';/*atamayı gerçekleştirdim*/
	board[7][5].type = 'S';/*atamayı gerçekleştirdim*/
	board[7][1].type = 'B';/*atamayı gerçekleştirdim*/
	board[6][9].type = 'T';/*atamayı gerçekleştirdim*/
	board[6][5].type = 'B';/*atamayı gerçekleştirdim*/
	board[6][1].type = 'M';/*atamayı gerçekleştirdim*/
	board[5][5].type = 'S';/*atamayı gerçekleştirdim*/
	board[5][2].type = 'P';/*atamayı gerçekleştirdim*/
	board[5][0].type = 'B';/*atamayı gerçekleştirdim*/
	board[4][9].type = 'S';/*atamayı gerçekleştirdim*/
	board[4][6].type = 'M';/*atamayı gerçekleştirdim*/
	board[4][3].type = 'T';/*atamayı gerçekleştirdim*/
	board[3][7].type = 'S';/*atamayı gerçekleştirdim*/
	board[3][4].type = 'B';/*atamayı gerçekleştirdim*/
	board[3][1].type = 'M';/*atamayı gerçekleştirdim*/
	board[2][8].type = 'T';/*atamayı gerçekleştirdim*/
	board[2][5].type = 'M';/*atamayı gerçekleştirdim*/
	board[2][2].type = 'S';/*atamayı gerçekleştirdim*/
	board[1][8].type = 'B';/*atamayı gerçekleştirdim*/
	board[1][5].type = 'P';/*atamayı gerçekleştirdim*/
	board[1][1].type = 'M';/*atamayı gerçekleştirdim*/
	board[0][8].type = 'S';/*atamayı gerçekleştirdim*/
	board[0][7].type = 'S';/*atamayı gerçekleştirdim*/
	board[0][2].type = 'T';	/*atamayı gerçekleştirdim*/	




	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			if (board[i][j].data == 1)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s",board[i][j].text);
			}
			else if (board[i][j].data == 6)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s       ",board[i][j].text);
			}
			else if (board[i][j].data == 7)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 13)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 17)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 25)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 29)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 32)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 36)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 40)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 45)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 48)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 50)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 54)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 57)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 60)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 63)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 66)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 69)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 73)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 76)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 79)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 82)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 85)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 89)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 93)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s          ",board[i][j].text);
			}
			else if (board[i][j].data == 98)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 99)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s      ",board[i][j].text);
			}
			else if (board[i][j].data == 100)/*olduğu yer integer değilde karakter olan kutucuk ekrana farklı basılır*/
			{
				printf("%s",board[i][j].text);
			}					
			else/*ekrana integer bir değer basmaso geriyorsa bu koşula girer*/
			{
				if (board[i][j].data < 10)/*tek haneli integer değerlerin ekrana  basılırken tabloda kayma olmaması için farklı koşula girer*/
				{
					printf("%d          ",board[i][j].data );
				}
				else/*çift haneli integer değerlerin ekrana basımı*/
				{
					printf("%d         ",board[i][j].data );
				}	
			}
		}
		printf("\n");
	}
}/*board kapama*/

int removal(block board[][10] ,int x ,int y ,int count,int steps)
{
	int r ,i ,k ;
	r = (rand() % 6) + 1;/*zarın yüzeyindeki gibi 1den 6'ya kadar rastkele değerler atanır*/
	i = 1; 

	if ((board[x][y].data + r) == 100 )/*son adım olduğunda yani oyun biteceği zaman buraya girer*/
	{
		printf("\n%d.adım=> x: %d   y: %d",steps,x,y+r);/*olduğu noktanın yani finish noktasının kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
		return 1;/*count olarak 1 döndürür*/
	}
	else if ((board[x][y].data + r) < 100 )/*eğer işlemlerden sonra dahi oyun devam edecekse bu koşula girer*/
	{
		while(i <= r)/*buradaki döngü pos_x ve pos_y değerlerinin to_x ve to_y değerlerinin olduğu yere dönüşmesini sağlar*/
		{
			if (x % 2 == 1)/*sağdan sola doğru artan satırlar buraya girer*/
			{
				y = y - 1;
				if (y < 0)
				{
						x = x - 1;
						y = 0;
				}			
			}
			else if(x % 2 == 0)/*soldan sağa doğru artan satırlar bu koşula girer*/
			{
				y = y + 1;
				if (y > 9)
				{
						x = x - 1;
						y = 9;
				}			
			}						
			i = i + 1;/*bir sonraki kutucuk üzerinden işlemler gerçekleşebilsin diye bir arttırım gerçekleştirdim*/
		}
		if (board[x][y].type == 'S')/*to_x to_y nin olduğu kordinant S tipi ise buraya girer*/
		{
			if (board[x][y].data == 6)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 9;
				y = 9;
			}
			else if (board[x][y].data == 25)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 8;
				y = 1;				
			}
			else if (board[x][y].data == 45)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 7;
				y = 8;				
			}
			else if (board[x][y].data == 60)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 5;
				y = 6;				
			}
			else if (board[x][y].data == 63)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 4;
				y = 1;				
			}
			else if (board[x][y].data == 73)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 3;
				y = 2;				
			}
			else if (board[x][y].data == 98)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 2;
				y = 1;				
			}
			else if (board[x][y].data == 99)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 4;
				y = 5;				
			}
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1);/*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/
		}/*S kapama*/	
		else if (board[x][y].type == 'M')/*to_x to_y nin olduğu kordinant M tipi ise buraya girer*/
		{
			if (board[x][y].data == 7)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 8;
				y = 0;
			}
			else if (board[x][y].data == 17)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 7;
				y = 2;				
			}
			else if (board[x][y].data == 32)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 4;
				y = 1;				
			}
			else if (board[x][y].data == 57)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 2;
				y = 6;				
			}
			else if (board[x][y].data == 69)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 2;
				y = 6;				
			}
			else if (board[x][y].data == 76)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 1;
				y = 7;				
			}
			else if (board[x][y].data == 89)/*olduğu kordinat için gerekli işlemleri yapar*/
			{
				x = 0;
				y = 3;				
			}
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1);/*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/			
		}/*M kapama*/
		else if (board[x][y].type == 'B')/*to_x to_y nin olduğu kordinant B tipi ise buraya girer*/
		{
			i = 1;
			while(i <= 5)/*olduğu sayıdan 5 ileri gidebilmek için atamaları yaptım*/
			{
				if (x % 2 == 1)/*sağdan sola doğru artan satırlar için*/
				{
					y = y - 1;
					if (y < 0)
					{
							x = x - 1;
							y = 0;
					}			
				}
				else if(x % 2 == 0)/*soldan sağa doğru artan satırlar için*/
				{

					y = y + 1;
					if (y > 9)
					{
							x = x - 1;
							y = 9;
					}			
				}						
				i = i + 1;
			}
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1);/*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/			
		}/*B kapama*/
		else if (board[x][y].type == 'T')/*to_x to_y nin olduğu kordinant T tipi ise buraya girer*/
		{
			i = 1;
			while(i <= 5)/*olduğu sayıdan 5 geri gidebilmek için atamaları yaptım*/
			{
				if (x % 2 == 1)/*sağdan sola doğru artan satırlar için*/
				{
					y = y + 1;
					if (y > 9)
					{
							x = x + 1;
							y = 9;
					}			
				}
				else if(x % 2 == 0)/*soldan sağa doğru artan satırlar için*/
				{
					y = y - 1;
					if (y < 0)
					{
							x = x + 1;
							y = 0;
					}			
				}						
				i = i + 1;
			}
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1);/*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/						
		}/*T kapama*/
		else if (board[x][y].type == 'P')/*to_x to_y nin olduğu kordinant P tipi ise buraya girer*/
		{
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1); /*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/			
		}/*P kapama*/
		else/*to_x to_y nin olduğu kordinant sayı tipi ise buraya girer*/
		{
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1); /*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/			
		}					
	}/*<=100 kapama*/
	else if ((board[x][y].data + r) > 100 )
	{
			count += 1;
			count = 1 + removal(board,x,y,count,steps + 1);/*count düzenli olarak recursive olarak güncellenir*/
			printf("\n%d.adım=> x: %d   y: %d",steps,x,y);/*olduğu noktanın kordinatlarını ve kaçıncı adım olduğunu ekrana basar*/
			return count;/*count düzenli olarak recursive olarak güncellenir*/
	}
}/*removal kapama*/	

void single_player(block board[][10])/*only one player can play there function*/
{
	int x = 9 ,y = 9 ,count = 0,steps = 1;/*oyunun başlangıç değerlerini tanımladım ve atamalarını yaptım*/
	printf("\nOne Player Game");	
	count = removal(board,x,y,count,steps);
	printf("\nOne player game of count : %d",count);
}

void multiplayer(block board[][10])/*two player can play this function*/
{
	int x = 9 ,y = 9 ,count_p1 = 0 ,count_p2 = 0 ,steps = 1;/*oyunun başlangıç değerlerini tanımladım ve atamalarını yaptım*/
	
	printf("\n\nMULTİPLAYER GAME\n");	
	printf("\nPLAYER1");
	count_p1 = removal(board,x,y,count_p1,steps);/*player1 için oyunu kaç hamlede bitirdiğini buldum*/
	printf("\n\nPLAYER2");
	count_p2 = removal(board,x,y,count_p2,steps);/*player2 için oyunu kaç hamlede bitirdiğini buldum*/

	if (count_p1 < count_p2)/*player1 in countu daha düşük ise kazanmıştır*/
	{
		printf("\nWinner is player1\n");
	}
	else if (count_p1 > count_p2)/*player1 in countu daha büyük ise kaybetmiştir*/
	{
		printf("\nWinner is player2\n");
	}
	else/*eşit olma durumları*/
	{
		printf("\nNo Winner!!!\n");
	}	
}	