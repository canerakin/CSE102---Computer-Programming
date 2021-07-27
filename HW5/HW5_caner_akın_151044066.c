#include <stdio.h>

/*typedef tanımlamaları*/
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;

/*kullanılmış olan tüm fonsiyonları tanımladım*/
void init_board(piece board[][8]);
void otomatik_yeme(piece board[][8], int from_x, int from_y, player p);/*kendi tanımladığım otomatik yeme yeme fonksiyonu*/
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y,player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_1();
void sample_game_2();

int main()
{
	piece board[8][8];/*genel olarak kodun tamamında kullanılacak olan piece arrayinin tanımladım*/
	init_board(board);/*board un başlangıç gösterimi*/
	sample_game_1();/*hazırladığım oyunun fonksiyonunu çağırdım*/
	sample_game_2();/*gifteki gibi olacak olan fonksiyonu çağırdım*/
	return 0;
}

void init_board(piece board[][8])/*normal bir oyun boardu*/
{
	int i,j;
	for (i = 0; i < 8; ++i)/*arrayin satır kısmı*/
	{
		for (j = 0; j < 8; ++j)/*arrayin sütun kısmı*/
		{
			board[i][j] = empty;		
		}
	}

	for (i = 0; i < 8; ++i)/*gerekli yerlere taşlar yerleştirilir*/
	{
		board[1][i] = black_man;
		board[2][i] = black_man;
		board[5][i] = white_man;
		board[6][i] = white_man;
	}
	display_board(board);/*ekrana yazma fonksiyonunu çağırdım*/
}

/*ilk yemeden sonra etrafındaki taşları yemek için çağırılan otomatik yeme fonksiyonu*/
/*tüm karakter taşları için geçerli bir fonksiyondur*/
void otomatik_yeme(piece board[][8], int from_x, int from_y ,player p)/*çağırıldığı noktadaki otomatik yemeleri yapar*/
{
	int i,king ,x ,y ,flag , count , flag_2 , count_2 = 0;
	king = 0;
	flag = 0;

	if (p == white)/*eğer beyaz taşlar için oynama yapılacaksa bu koşula girer*/
	{
		if (board[from_x][from_y] == white_king)/*white_king in otomatik yeme  ihtimalleri*/
		{
			i = 1;
			while(flag == 0)/*flag 1 olduğunca yani yeme devam ettiği sürece döner*/
			{
				count_2 = 0;
				if (board[from_x][from_y-1] != white_man && board[from_x][from_y-1] != white_king )/*sola taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x][from_y-2] == empty && (board[from_x][from_y-1] == black_man || board[from_x][from_y-1] == black_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y-1] = empty;
						board[from_x][from_y-2] = white_king;
						from_y = from_y - 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x][from_y-i] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x][from_y-1-i] == empty && (board[from_x][from_y-i] == black_man || board[from_x][from_y-i] == black_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;/*atamaları gerçekleştirdim*/
							board[from_x][from_y-1] = empty;
							board[from_x][from_y-2] = white_king;
							from_y = from_y - 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}

				if (board[from_x][from_y+1] != white_man && board[from_x][from_y+1] != white_king )/*sağa taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x][from_y+2] == empty && (board[from_x][from_y+1] == black_man || board[from_x][from_y+1] == black_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y+1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y+2] = white_king;
						from_y = from_y + 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x][from_y+i] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x][from_y+1+i] == empty && (board[from_x][from_y+i] == black_man || board[from_x][from_y+i] == black_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x][from_y+1] = empty;/*atamaları gerçekleştirdim*/
							board[from_x][from_y+2] = white_king;
							from_y = from_y + 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}

	
				if (board[from_x][from_y-1] != white_man && board[from_x][from_y-1] != white_king )/*yukarı taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x-2][from_y] == empty && (board[from_x-1][from_y] == black_man || board[from_x-1][from_y] == black_king))/*yanındaki taşı yer*//*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x-1][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x-2][from_y] = white_king;
						from_x = from_x - 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x-i][from_y] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x-1-i][from_y] == empty && (board[from_x-i][from_y] == black_man || board[from_x-i][from_y] == black_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x-1][from_y] = empty;/*atamaları gerçekleştirdim*/
							board[from_x-2][from_y] = white_king;
							from_x = from_x - 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}											

				if (board[from_x][from_y+1] != white_man && board[from_x][from_y+1] != white_king )/*aşağı taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x+2][from_y] == empty && (board[from_x+1][from_y] == black_man || board[from_x+1][from_y] == black_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x+1][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x+2][from_y] = white_king;
						from_x = from_x + 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x+i][from_y] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x+1+i][from_y] == empty && (board[from_x+i][from_y] == black_man || board[from_x+i][from_y] == black_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x+1][from_y] = empty;/*atamaları gerçekleştirdim*/
							board[from_x+2][from_y] = white_king;
							from_x = from_x + 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}
				if(count_2 = 0)/*herhangi bir yeme ihtimali yoksa döngüden çıkar*/
				{
					flag = 1;
				}	
			}/*while bitimi*/
			
		}/*white_king bitimi*/


		else if (board[from_x][from_y] == white_man)/*white_man in otomatik yeme  ihtimalleri*/
		{
			while(flag == 0)/*white_man in otomatik yiyeceği taş kalmayıncaya kadar devam eder*/
			{
				count = 0;
				if (from_y > 1 && (board[from_x][from_y - 2] == empty && count == 0))/*sola taraf atlayarak yeme*/
				{
					if (board[from_x][from_y-1] == black_man || board[from_x][from_y-1] == black_king)/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y-1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y-2] = white_man;
						from_y = from_y - 2;
						count = count + 1;
					}
				}

				if (from_y < 6 && (board[from_x][from_y + 2] == empty && count == 0))/*sağa taraf atlayarak yeme*/
				{
					if (board[from_x][from_y+1] == black_man || board[from_x][from_y+1] == black_king)/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y+1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y+2] = white_man;
						from_y = from_y + 2;
						count = count + 1;
					}
				}				

				if (board[from_x-2][from_y] == empty && count == 0)/*ileriye doğru otomatik olarak yeme*/
				{
					if (board[from_x-1][from_y] == black_man || board[from_x-1][from_y] == black_king)/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x-1][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x-2][from_y] = white_man;
						from_x = from_x - 2;
						count = count + 1;
						if (from_x == 0)/*king olama durumu*/
						{
							board[from_x][from_y] = white_king;
							count = 0;
						}
						
						
					}
				}


				if (count == 0)/*herhangi bir yeme ihtimali yoksa döngüden çıkar*/
				{
					flag = 1;
				}					

			}/*while kapama*/


		}/*white_man kapama*/		


	}/*white kapama*/

	else if (p == black)
	{
		if (board[from_x][from_y] == black_king)/*black_king in otomatik yeme  ihtimalleri*/
		{
			i = 1;
			while(flag == 0)
			{
				count_2 = 0;
				if (board[from_x][from_y-1] != black_man && board[from_x][from_y-1] != black_king )/*sola taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x][from_y-2] == empty && (board[from_x][from_y-1] == white_man || board[from_x][from_y-1] == white_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y-1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y-2] = black_king;
						from_y = from_y - 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x][from_y-i] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x][from_y-1-i] == empty && (board[from_x][from_y-i] == white_man || board[from_x][from_y-i] == white_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x][from_y-1] = empty;/*atamaları gerçekleştirdim*/
							board[from_x][from_y-2] = black_king;
							from_y = from_y - 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}

				if (board[from_x][from_y+1] != black_man && board[from_x][from_y+1] != black_king )/*sağa taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x][from_y+2] == empty && (board[from_x][from_y+1] == white_man || board[from_x][from_y+1] == white_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y+1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y+2] = black_king;
						from_y = from_y + 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x][from_y+i] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x][from_y+1+i] == empty && (board[from_x][from_y+i] == white_man || board[from_x][from_y+i] == white_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x][from_y+1] = empty;/*atamaları gerçekleştirdim*/
							board[from_x][from_y+2] = black_king;
							from_y = from_y + 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}

	
				if (board[from_x][from_y-1] != black_man && board[from_x][from_y-1] != black_king )/*yukarı taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x-2][from_y] == empty && (board[from_x-1][from_y] == white_man || board[from_x-1][from_y] == white_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x-1][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x-2][from_y] = black_king;
						from_x = from_x - 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x-i][from_y] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x-1-i][from_y] == empty && (board[from_x-i][from_y] == white_man || board[from_x-i][from_y] == white_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x-1][from_y] = empty;/*atamaları gerçekleştirdim*/
							board[from_x-2][from_y] = black_king;
							from_x = from_x - 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}											

				if (board[from_x][from_y+1] != black_man && board[from_x][from_y+1] != black_king )/*aşağı taraf atlayarak yeme*/
				{
					i = 1;
					flag_2 = 0;
					if (board[from_x+2][from_y] == empty && (board[from_x+1][from_y] == white_man || board[from_x+1][from_y] == white_king))/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x+1][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x+2][from_y] = black_king;
						from_x = from_x + 2;
						count_2 = 1;
						flag = 1;
					}
					else
					{
						while(board[from_x+i][from_y] == empty)/*aradaki boşlukları saymak için kullandım*/
						{
							i = i + 1;
						}
						if (board[from_x+1+i][from_y] == empty && (board[from_x+i][from_y] == white_man || board[from_x+i][from_y] == white_king))/*aralarında bosluk olsa dahi yer*/
						{
							display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
							board[from_x][from_y] = empty;
							board[from_x+1][from_y] = empty;/*atamaları gerçekleştirdim*/
							board[from_x+2][from_y] = black_king;
							from_x = from_x + 2;
							count_2 = 1;
							flag = 1;
						}
						else/*yiyememe durumunda çıkar*/
						{
							flag = 1;
						}
					}
				}
				if(count_2 = 0)/*herhangi bir yeme ihtimali yoksa döngüden çıkar*/
				{
					flag = 1;
				}									
			}/*while bitimi*/			
			
		}/*black_king kapama*/

		else if (board[from_x][from_y] ==black_man)/*black_man in otomatik yeme  ihtimalleri*/
		{
			while(flag == 0)/*white_man in otomatik yiyeceği taş kalmayıncaya kadar devam eder*/
			{
				count = 0;
				if (from_y > 1 && (board[from_x][from_y - 2] == empty && count == 0))/*sola taraf atlayarak yeme*/
				{

					if (board[from_x][from_y-1] == white_man || board[from_x][from_y-1] == white_king)/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y-1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y-2] = black_man;
						from_y = from_y - 2;
						count = count + 1;	
					}
				}

				if (from_y < 6 && (board[from_x][from_y + 2] == empty && count == 0))/*sağa taraf atlayarak yeme*/
				{
					if (board[from_x][from_y+1] == white_man || board[from_x][from_y+1] == white_king)/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x][from_y+1] = empty;/*atamaları gerçekleştirdim*/
						board[from_x][from_y+2] = black_man;
						from_y = from_y + 2;
						count = count + 1;
						
					}
				}				

				if (board[from_x+2][from_y] == empty && count == 0)/*ileriye doğru otomatik olarak yeme*/
				{
					if (board[from_x+1][from_y] == white_man || board[from_x+1][from_y] == white_king)/*yanındaki taşı yer*/
					{
						display_board(board);/*kendinden önceki yenmiş olan taşıda ekrana yazar*/
						board[from_x][from_y] = empty;
						board[from_x+1][from_y] = empty;/*atamaları gerçekleştirdim*/
						board[from_x+2][from_y] = black_man;
						count = count + 1;
						from_x = from_x + 2;
						if (from_x == 7)/*king olama durumu*/
						{
							board[from_x][from_y] = black_king;
							count = 0;
						}
						
					
					}
				}
				if (count == 0)/*herhangi bir yeme ihtimali yoksa döngüden çıkar*/
				{
					flag = 1;
				}

			}/*while kapama*/

		}/*black_man kapama*/
	}


}

/*hareket edilecek yerin gidip gidemeyeceği veya yiyip yiyemeyeceği burada gerçekleşir*/
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y,player p)
{
	int i ,king ,x ,y;
	king = 0;

	if (p == white)/*seçilen karakter taşı beyaz ise bu döngüye girer*/
	{
		if (board[from_x][from_y] == white_king) /*white_king hareket ettirme*/
		{
			if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
				return -2;
			}
			else if (from_x < to_x && to_y == from_y)/*aşağı hareket*/
			{
				for (i = 1; i <= to_x - from_x; ++i)
				{
					if (board[from_x + i][from_y] == black_man || board[from_x + i][from_y] == black_king)
					{
						king = king + 1;
						x = from_x + i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_king;
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[x][from_y] = empty;
					board[to_x][to_y] = white_king;/*atamaları yaptım*/
					otomatik_yeme(board ,to_x ,to_y ,p);
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;
			}
			else if (from_x > to_x && to_y == from_y)/*yukarıya hareket*/
			{
				for (i = 1; i <= from_x - to_x; ++i)
				{
					if (board[from_x - i][from_y] == black_man || board[from_x - i][from_y] == black_king)
					{
						king = king + 1;
						x = from_x - i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_king;/*atamaları yaptım*/
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[x][from_y] = empty;
					board[to_x][to_y] = white_king;/*atamaları yaptım*/
					otomatik_yeme(board ,to_x ,to_y ,p);
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;	
			}
			else if (from_x == to_x && to_y < from_y)/*sağa hareket*/
			{
				for (i = 1; i <= from_y - to_y; ++i)
				{
					if (board[from_x][from_y - i] == black_man || board[from_x][from_y - i] == black_king)
					{
						king = king + 1;
						x = from_y - i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_king;
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[from_x][x] = empty;
					board[to_x][to_y] = white_king;/*atamaları yaptım*/
					otomatik_yeme(board ,to_x ,to_y ,p);
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;
			}
			else if (from_x == to_x && to_y > from_y)/*sola hareket*/
			{
				for (i = 1; i <= to_y - from_y ; ++i)
				{
					if (board[from_x][from_y + i] == black_man || board[from_x][from_y + i] == black_king)
					{
						king = king + 1;
						x = from_y + i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_king;
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[from_x][x] = empty;
					board[to_x][to_y] = white_king;/*atamaları yaptım*/
					otomatik_yeme(board ,to_x ,to_y ,p);
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;
			}
			else/*oynanmak istenen yer boş değilse oynanamaz der*/
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
				return -2;
			}
		}	

		else if (board[from_x][from_y] == white_man)
		{
			if (from_x < to_x)/*geriye hareket etmeyi önlemek için kullandım*/
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
				return -2;
			} 


			



			/*tek hareket olarak white_man hareketi*/			
			else if (from_x == to_x + 1 && from_y == to_y)/*düz ilerleme*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yerin boş olmadığı durumlardır */
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");					
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa atamayı yapar*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_man;/*atamaları yaptım*/
					if (to_x == 0)
					{
						board[to_x][to_y] = white_king;
					}					
					return 0;
				}
			}
			else if (from_x == to_x && from_y == to_y - 1)/*sağa hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istene yer boş değilse buraya girer*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa atamayı yapar*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_man;/*atamaları yaptım*/
					
					return 0;
				}
			}
			else if (from_x == to_x && from_y == to_y + 1) /*sola hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa atamayı yapar*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = white_man;/*atamaları yaptım*/
					
					return 0;
				}
			}


			/*yemek için kullanılan white_man*/
			else if (from_x == to_x + 2 && from_y == to_y )/*düz ilerleme*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yerin boş olmadığı durumlardır */
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");					
					return -2;
				}

				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa kontrollere girer*/
				{
					if (board[from_x-1][from_y] == black_man || board[from_x-1][from_y] == black_king)/*yeme olayı burada gerçekleşir*/
					{
						board[from_x][from_y] = empty;
						from_x = from_x - 1;
						board[from_x][from_y] = empty;/*atamaları yaptım*/
						board[to_x][to_y] = white_man;

						otomatik_yeme(board ,to_x ,to_y ,p);

						if (to_x == 0)
						{
							board[to_x][to_y] = white_king;
						}
						return 0;
					}
					else 				
					{
						return -2;
					}
				}
			}
			else if (from_x == to_x && from_y == to_y - 2)/*sağa hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yerin boş olmadığı durumlardır */
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");					
					return -2;
				}

				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa kontrollere girer*/
				{
					if (board[from_x][from_y + 1] == black_man || board[from_x][from_y + 1] == black_king)/*yeme olayı burada gerçekleşir*/
					{
						board[from_x][from_y] = empty;
						from_y = from_y + 1;						
						board[from_x][from_y] = empty;/*atamaları yaptım*/
						board[to_x][to_y] = white_man;

						otomatik_yeme(board ,to_x ,to_y ,p);

						return 0;
					}
					else 				
					{
						return -2;
					}
				}
			}
			else if (from_x == to_x && from_y == to_y + 2) /*sola hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa kontrollere girer*/
				{
					if (board[from_x][from_y - 1] == black_man || board[from_x][from_y - 1] == black_king)/*yeme olayı burada gerçekleşir*/
					{
						board[from_x][from_y] = empty;
						from_y = from_y - 1;
						board[from_x][from_y] = empty;/*atamaları yaptım*/
						board[to_x][to_y] = white_man;

						otomatik_yeme(board ,to_x ,to_y ,p);

						return 0;
					}
					else 				
					{
						return -2;
					}
				}
			}	

			else
			{
				printf("\nkendi taşınızı oynayınız.\n");			
				return -1;
			}	
		}			
		
	}

	if (p == black)
	{
		if (board[from_x][from_y] == black_king)
		{
			if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
				return -2;
			}
			else if (from_x < to_x && to_y == from_y)/*aşağı hareket*/
			{
				for (i = 1; i <= to_x - from_x; ++i)
				{
					if (board[from_x + i][from_y] == white_man || board[from_x + i][from_y] == white_king)
					{
						king = king + 1;
						x = from_x + i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = black_king;/*atamayı yaptım*/
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;/*atamayı yaptım*/
					board[x][from_y] = empty;
					board[to_x][to_y] = black_king;
					otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;
			}
			else if (from_x > to_x && to_y == from_y)/*yukarıya hareket*/
			{
				for (i = 1; i <= from_x - to_x; ++i)
				{
					if (board[from_x - i][from_y] == white_man || board[from_x - i][from_y] == white_king)
					{
						king = king + 1;
						x = from_x - i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = black_king;
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[x][from_y] = empty;
					board[to_x][to_y] = black_king;/*atamayı yaptım*/
					otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;	
			}
			else if (from_x == to_x && to_y < from_y)/*sağa hareket*/
			{
				for (i = 1; i <= from_y - to_y; ++i)
				{
					if (board[from_x][from_y - i] == white_man || board[from_x][from_y - i] == white_king)
					{
						king = king + 1;
						x = from_y - i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = black_king;
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[from_x][x] = empty;
					board[to_x][to_y] = black_king;/*atamayı yaptım*/
					otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;
			}
			else if (from_x == to_x && to_y > from_y)/*sola hareket*/
			{
				for (i = 1; i <= to_y - from_y ; ++i)
				{
					if (board[from_x][from_y + i] == white_man || board[from_x][from_y + i] == white_king)
					{
						king = king + 1;/*atamayı yaptım*/
						x = from_y + i;
					}
				}
				if (king == 0)/*arada yenecek taş yoksa buraya girer*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = black_king;
					return 0;
				}
				else if (king == 1)/*arada yenecek taş varsa buraya girer*/
				{
					board[from_x][from_y] = empty;/*atamayı yaptım*/
					board[from_x][x] = empty;
					board[to_x][to_y] = black_king;
					otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/
					return 0;
				}	
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");							
				return -2;
			}
			else
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
				return -2;
			}
		}

		else if (board[from_x][from_y] == black_man)/*eğer seçilen yer black_man ise buraya girer*/
		{
			if (from_x > to_x)/*geriye hareket etmeyi önlemek için kullandım*/
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");				
				return -2;
			} 	



			/*düz ilerleme için black_man */
			else if (from_x == to_x - 1 && from_y == to_y)/*düz ilerleme*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
					return -2;
				}
				else if (board[to_x][to_y] == empty)
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = black_man;/*atamayı yaptım*/
					if (to_x == 7)
					{
						board[to_x][to_y] = black_king;/*atamayı yaptım*/
					}					
					return 0;
				}
			}
			else if (from_x == to_x && from_y == to_y - 1)/*sağa hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");		
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gidilecek yer boşsa atamaları yapar*/
				{
					board[from_x][from_y] = empty;
					board[to_x][to_y] = black_man;/*atamayı yaptım*/
					
					return 0;
				}
			}
			else if (from_x == to_x && from_y == to_y + 1) /*sola hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");					
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gidilecek yer boşsa atamaları yapar*/
				{
					board[from_x][from_y] = empty;/*atamayı yaptım*/
					board[to_x][to_y] = black_man;

					return 0;
				}
			}


			/*yeme için black_man*/
			else if (from_x == to_x - 2 && from_y == to_y)/*düz ilerleme*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yerin boş olmadığı durumlardır */
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");					
					return -2;
				}

				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa kontrollere girer*/
				{
					if (board[from_x+1][from_y] == white_man || board[from_x+1][from_y] == white_king)/*yeme olayı burada gerçekleşir*/
					{
						board[from_x][from_y] = empty;
						from_x = from_x + 1;						
						board[from_x][from_y] = empty;
						board[to_x][to_y] = black_man;/*atamayı yaptım*/

						otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/

						if (to_x == 7)/*king olma durumu*/
						{
							board[to_x][to_y] = black_king;
						}
						return 0;
					}
					else 				
					{
						return -2;
					}
				}
			}
			else if (from_x == to_x && from_y == to_y - 2) /*sağa hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa kontrollere girer*/
				{
					if (board[from_x][from_y + 1] == white_man || board[from_x][from_y + 1] == white_king)/*yeme olayı burada gerçekleşir*/
					{
						board[from_x][from_y] = empty;
						from_y = from_y + 1;						
						board[from_x][from_y] = empty;/*atamayı yaptım*/
						board[to_x][to_y] = black_man;

						otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/

						return 0;
					}
					else 				
					{
						return -2;
					}
				}
			}
			else if (from_x == to_x && from_y == to_y + 2) /*sola hareket*/
			{
				if (board[to_x][to_y] != empty)/*oynanmak istenen yer boş değilse oynanamaz der*/
				{
					printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");
					return -2;
				}
				else if (board[to_x][to_y] == empty)/*gideceği yer boş olursa kontrollere girer*/
				{
					if (board[from_x][from_y - 1] == white_man || board[from_x][from_y - 1] == white_king)/*yeme olayı burada gerçekleşir*/
					{
						board[from_x][from_y] = empty;/*atamayı yaptım*/
						from_y = from_y - 1;						
						board[from_x][from_y] = empty;
						board[to_x][to_y] = black_man;/*atamayı yaptım*/

						otomatik_yeme(board ,to_x ,to_y ,p);/*geldiği yerde yiyebileceği taşlar varmı diye kontrol eder.varsa yer*/

						return 0;
					}
					else 				
					{
						return -2;
					}
				}
			}			


			else
			{
				printf("\ntaşınızın kordinata oynama ihtimali yoktur oynayamazsınız.Tekrar secim yapınız.\n");				
				return -2;
			}
		}

		else
		{
			printf("\nkendi taşınızı oynayınız.\n");			
			return -1;
		}
		
	}
}

int check_end_of_game(piece board[][8])/*oyunun bitip bitmediğini kontrol eden fonksiyon*/
{
	int i , j;
	int white_sayisi = 0,black_sayisi =0;

	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			if (board[i][j] == white_man || board[i][j] == white_king)/*eğer kordinattaki karakter white kullanıcısına aitse sayacı arttırır*/
			{
				white_sayisi = white_sayisi + 1;
			}
			else if (board[i][j] == black_man || board[i][j] == black_king)/*eğer kordinattaki karakter black kullanıcısına aitse sayacı arttırır*/
			{
				black_sayisi = black_sayisi + 1;
			}
		}
	}
	if (white_sayisi == 0)/*white taşları bittiyse black kazanır*/
	{
		printf("winner is black\n");
		return 0;
	}
	else if (black_sayisi == 0)/*black taşları bittiyse white kazanır*/
	{
		printf("winner is white\n");
		return 0;
	}
	else/*iki tarafında taşı bitmediyse oyun devam eder*/
	{
		printf("game continues\n");
		return -1;
	}
	
}

void display_board(piece board[][8])/*ekrana yazma fonksiyonu*/
{
	int i,j;/*iç içe for için kullanılacak*/

	printf("\n01234567\n");

	for (i = 0; i < 8; ++i)/*yatay düzlemin parametresidir*/
	{
		for (j = 0; j < 8; ++j)/*dikey düzlemin parametresidir*/
		{
			if (board[i][j] == white_man)/*değer white_man ise ekrana w yazar*/
			{
				printf("w");
			}
			else if (board[i][j] == black_man)/*değer black_man ise ekrana b yazar*/
			{
				printf("b");
			}
			else if (board[i][j] == white_king)/*değer white_king ise ekrana W yazar*/
			{
				printf("W");
			}
			else if (board[i][j] == black_king)/*değer black_king ise ekrana B yazar*/
			{
				printf("B");
			}
			else if (board[i][j] == empty)/*değer empty ise ekrana - yazar*/
			{
				printf("-");
			}		
		}
		printf("  %d.satır\n",i);/*yatay düzlemin satır isimlerini ekrana yazar*/
	}
	printf("\n");
}


void sample_game_1()
{
	piece board[8][8];
	int i , j ,r_move;


	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			board[i][j] = empty;	/*tahtayı boş atadım*/	
		}
	}	

	board[1][1] = black_man;/*tahtadaki yerini atadım*/
	board[1][2] = black_man;/*tahtadaki yerini atadım*/
	board[2][0] = black_man;/*tahtadaki yerini atadım*/
	board[2][2] = black_man;/*tahtadaki yerini atadım*/
	board[2][4] = black_man;/*tahtadaki yerini atadım*/
	board[2][6] = black_man;/*tahtadaki yerini atadım*/
	board[3][5] = black_man;/*tahtadaki yerini atadım*/
	board[3][7] = black_man;/*tahtadaki yerini atadım*/
	board[4][4] = black_man;/*tahtadaki yerini atadım*/

	board[4][0] = white_man;/*tahtadaki yerini atadım*/
	board[4][1] = white_man;/*tahtadaki yerini atadım*/
	board[4][6] = white_man;/*tahtadaki yerini atadım*/
	board[5][0] = white_man;/*tahtadaki yerini atadım*/
	board[5][2] = white_man;/*tahtadaki yerini atadım*/
	board[5][7] = white_man;/*tahtadaki yerini atadım*/
	board[6][0] = white_man;/*tahtadaki yerini atadım*/
	board[6][2] = white_man;/*tahtadaki yerini atadım*/
	board[6][5] = white_man;/*tahtadaki yerini atadım*/
	board[6][6] = white_man;/*tahtadaki yerini atadım*/
	board[6][7] = white_man;/*tahtadaki yerini atadım*/

	printf("\nSAMPLE_GAME_1\n");

	display_board(board);

	r_move = move(board,4,0,3,0,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,2,0,4,0,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,2,3,2,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,2,2,4,2,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/	
								
	r_move = move(board,6,2,6,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,2,5,2,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,6,5,5,5,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,4,5,4,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,5,5,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,1,2,2,2,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,6,4,7,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,3,5,4,5,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/			
	
	r_move = move(board,4,7,2,7,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,5,5,5,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,0,1,0,5,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,5,5,4,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,6,3,5,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,4,5,2,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,1,5,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

}


void sample_game_2()
{
	piece board[8][8];
	int i , j ,r_move;


	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			board[i][j] = empty;	/*tahtayı boş atadım*/	
		}
	}
	for (i = 0; i < 4; ++i)
	{
		board[1][2+i] = black_man;/*tahtadaki yerini atadım*/
		board[2][1+i] = black_man;/*tahtadaki yerini atadım*/
		board[6][2+i] = white_man;/*tahtadaki yerini atadım*/
	}
	for (i = 0; i < 3; ++i)
	{
		board[3][i] = black_man;/*tahtadaki yerini atadım*/
		board[4][2+i] = white_man;/*tahtadaki yerini atadım*/
	}
	for (i = 0; i < 8; ++i)
	{
		if (i != 5)
		{
			board[5][i] = white_man;/*tahtadaki yerini atadım*/
		}
	}
	for (i = 0; i < 2; ++i)
	{
		board[4][6+i] = white_man;/*tahtadaki yerini atadım*/
		board[2][6+i] = black_man;/*tahtadaki yerini atadım*/
		board[3+i][5] = black_man;/*tahtadaki yerini atadım*/
	}
	board[3][7] = black_man;

	printf("\nSAMPLE_GAME_2\n");

	display_board(board);

	r_move = move(board,5,1,4,1,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,3,1,5,1,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,3,3,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,5,4,3,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,3,3,3,1,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,1,2,1,0,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,3,4,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,1,5,3,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,3,3,3,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,2,3,4,3,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,5,6,5,5,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,7,5,4,5,black);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/

	r_move = move(board,4,6,4,4,white);/*oynamak için fonksiyona kordinant gönderdim*/
	display_board(board);/*anlık ekranı günceller*/
	check_end_of_game(board);/*anlık kazananı ve devam etmeyi kontrol eder*/
}
