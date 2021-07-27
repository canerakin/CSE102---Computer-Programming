#include <stdio.h>
#define AY 12 /*bir yıl içindeki toplam ay sayısı 12 olarak tanımladım*/
/*ayları typedef olarak tanımladım*/
typedef enum {january = 1 ,february ,march ,april ,may ,june ,july ,august ,september ,october ,november ,december} aylar;
/*günleri typedef olarak tanımladım*/
typedef enum {sunday = 1,monday = 2,tuesday = 3,wednesday = 4,thursday = 5,friday = 6,saturday = 0} gunler;

int main()
{
	FILE * inp;/*bir klasör tanımladım*/
	FILE * new;/*bir klasör tanımladım*/
	int ilk_gun,son_gun,ilk_ay,son_ay,ilk_yil,son_yil;
	int fark = 0,today,i=0;
	int fark_2;
	printf("\nsırayla giriniz:");/*kullanıcıdan tarihler alınır*/
	printf("\nilk gün: ");
	scanf("%d",&ilk_gun);
	printf("\nilk ay: ");/*kullanıcıdan ilk tarihler alınır*/
	scanf("%d",&ilk_ay);	
	printf("\nilk yıl: ");
	scanf("%d",&ilk_yil);	

	printf("\nson gün: ");
	scanf("%d",&son_gun);
	printf("\nson ay: ");/*kullanıcıdan son tarihler alınır*/
	scanf("%d",&son_ay);
	printf("\nson yıl: ");
	scanf("%d",&son_yil);

	inp = fopen("input_date.txt","wb");/*input_date.txt dosyasını yazılabilecek şekilde açtım*/
	new = fopen("new_date.txt","w");/*new_date.txt dosyasını yazılabilecek şekilde açtım*/
	

	do/*döngüye direk girer*/
	{
		if (ilk_gun > 31 && ilk_ay == january)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 28 && ilk_ay == february && ilk_yil % 4 != 0)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 29 && ilk_ay == february && ilk_yil % 4 == 0)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}		
		else if (ilk_gun > 31 && ilk_ay == march)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}		
		else if (ilk_gun > 30 && ilk_ay == april)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 31 && ilk_ay == may)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 30 && ilk_ay == june)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 31 && ilk_ay == july)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 31 && ilk_ay == august)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 30 && ilk_ay == september)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 31 && ilk_ay == october)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 30 && ilk_ay == november)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}
		else if (ilk_gun > 31 && ilk_ay == december)/*birdahaki aya devretme şartı*/
		{
			ilk_gun = 1;/*ilk gün sıfırlanr*/
			ilk_ay = ilk_ay + 1;/*bir sonraki aya devir ataması*/
		}

		if (ilk_ay > AY)
		{
			ilk_ay = 1;/*bir sonraki yıla devir ataması*/
			ilk_yil = ilk_yil +1;/*bir sonraki yıl ataması*/
		}
		fprintf(inp,"%d/%d/%d ",ilk_gun,ilk_ay,ilk_yil);/*anlık değerleri input dosyasına yazar*/
		fprintf(inp,"%c",'\n');
		fark = (son_gun + son_ay * 30 + son_yil * 30 * 12) - (ilk_gun + ilk_ay * 30 + ilk_yil * 30 * 12);/*iki tarih arasında ne kadar zaman kaldığını kontrol eder */
		ilk_gun = ilk_gun + 1;/*bir sonraki güne geçiş*/
	}while(fark > 0);/*son günüde basar ve döngüden çıkar*/
		fprintf(inp,"%s","\0");	

		fclose(inp);/*input_date.txt dosyasını kapattım*/
		inp = fopen("input_date.txt","r");/*okuma yapmak için input_date.txt dosyasını açtım*/

	while(fscanf(inp,"%d%*c%d%*c%d%*c",&ilk_gun,&ilk_ay,&ilk_yil) != EOF )/*döngüye direk girer*/
	{
		//fscanf(inp,"%d%*c",&ilk_gun);/*input dosysından anlık değerler alır*/
		//fscanf(inp,"%d%*c",&ilk_ay);/*input dosysından anlık değerler alır*/
		//fscanf(inp,"%d%*c",&ilk_yil);/*input dosysından anlık değerler alır*/



		if (ilk_ay == january)/*anlık tarihin january olma durumunda buraya girer*/ 
		{
			fark_2 = ((ilk_gun % 7) + 1 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7) - 1 ;/*hangi gün olduğunu bulan işlemler*/
			if ((ilk_yil) % 4 == 0)/*artık yıl dönemlerinin koşulu*/
			{
				fark_2 = fark_2 - 1;
			}
			fark_2 = fark_2 % 7;			
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,January %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
		}
		else if (ilk_ay == february)/*anlık tarihin february olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 4 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			if ((ilk_yil) % 4 == 0)/*artık yıl dönemlerinin koşulu*/
			{
				fark_2 = fark_2 - 1;
			}
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,February %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}			
		}
		else if (ilk_ay == march)/*anlık tarihin march olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 4 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,March %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
		}
		else if (ilk_ay == april)/*anlık tarihin april olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 7 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,April %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}		
		}
		else if (ilk_ay == may)/*anlık tarihin may olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 2 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,May %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}	
		}
		else if (ilk_ay == june)/*anlık tarihin june olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 5 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,June %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}		
		}
		else if (ilk_ay == july)/*anlık tarihin july olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 7 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,July %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}	
		}
		else if (ilk_ay == august)
		{
			fark_2 = (ilk_gun % 7) + 3 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/		
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,August %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
		}
		else if (ilk_ay == september)
		{
			fark_2 = (ilk_gun % 7) + 6 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,September %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}	
		}
		else if (ilk_ay == october)
		{
			fark_2 = (ilk_gun % 7) + 1 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,October %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}	
		}		
		else if (ilk_ay == november)
		{
			fark_2 = (ilk_gun % 7) + 4 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,November %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}	
		}		
		else if (ilk_ay == december)/*anlık tarihin december olma durumunda buraya girer*/ 
		{
			fark_2 = (ilk_gun % 7) + 6 + (ilk_yil % 100) % 7 + ((ilk_yil % 100) / 4) % 7 - 1;/*hangi gün olduğunu bulan işlemler*/
			fark_2 = fark_2 % 7;
			if (fark_2 == monday)
			{
				fprintf(new,"Monday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == tuesday)
			{
				fprintf(new,"Tuesday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == wednesday)
			{
				fprintf(new,"Wednesday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == thursday)
			{
				fprintf(new,"Thursday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == friday)
			{
				fprintf(new,"Friday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == saturday)
			{
				fprintf(new,"Saturday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
			else if (fark_2 == sunday)
			{
				fprintf(new,"Sunday,December %d,%d\n",ilk_gun,ilk_yil);/*anlık değerleri input dosyasına yazar*/
			}
		}		
	}/*son günüde basar ve döngüden çıkar*/

	
	fclose(new);/*new_date.txt klasörü kapanır*/
	fclose(inp);/*input_date.txt klasörü kapanır*/

	return 0;
}
