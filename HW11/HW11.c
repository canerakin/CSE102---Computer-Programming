#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct must/*struct tanımlamalarını yaptım*/
{
	char *soyad;
	char *ad;
	int yas;
	int oda;
	char *cinsiyet;
	struct must *next;
}musteri;



typedef struct odalar/*struct tanımlamalarını yaptım*/
{
	int sayi;
	int kapasite;
	int kat;
	struct odalar *next;
	musteri *n;
}oda;

/*FONKSİYONLARI TANIMLARKEN RETURN DEĞERLERİ LİSTENİN BAŞINI RETURN EDER*/

/*dosyadan okunan değeri listeye bağlayan fonksiyonu tanımladım*/
oda * add_room_to_end(oda * root ,int oda_no ,int kapasite ,int oda_kat);
oda * add_room_after_room_number(oda * root);/*oda ekleme fonksiyonunu tanımladım*/
oda * remove_room(oda * root);/*oda silme fonsiyonunu tanımladım*/
oda * get_by_floor(oda * root);/*istenilen kattaki odaları ekrana basar*/
musteri * add_customer_to_end(musteri * head ,int yas ,char ad[] ,char soyad[] ,char cinsiyet[],int oda);
/*müşterileri birbirine bağlayan fonsiyonu tanımladım*/

int main()
{
	FILE * dosya;/*rooms klasörü için bir klasör tanımladım*/
	int oda_no ,oda_kapasite ,oda_kat ,yas ,i;
	char isim[11] ,soyisim[11] ,cinsiyet[7],bos ,virgul , son;
	virgul = ',';/*atamaları yaptım*/
	son = '\n';


	oda * root = NULL;/*listeyi en başta boş olmasını atadım*/

	dosya = fopen("rooms.txt","r");/*dosyayı okumak için açtım*/
	while(!feof(dosya))/*dosyadaki taranmamış eleman kalmayana kadar devam eder*/
	{
		fscanf(dosya,"%d,%d,%d",&oda_no,&oda_kapasite,&oda_kat);/*dosyadan harf olarak satırın hepsini alınır*/
		root = add_room_to_end(root ,oda_no ,oda_kapasite ,oda_kat);/*listeye bağlanması için fonksiyona gönderilir*/
	}
	fclose(dosya);/*dosyayı kapttım*/

	root = add_room_after_room_number(root);/*ekleme fonksiyonunu çağırdım*/
	root = remove_room(root);/*silme fonksiyonunu çağırdım*/
	root = get_by_floor(root);/*istenilen katları ekrana yazan fonksiyonu çağırdım*/

	oda * try = root;/*klasörün başını kaybetmemek için kullandım*/
	printf("--Rooms klasöründen alınarak ve değişikliklere uğrayarak bağlanmış listedeki değerler--\n");
	while(root != NULL)/*listedeki değerleri ekrana yazar*/
	{
		printf("%d,%d,%d\n",root->sayi,root->kapasite,root->kat);
		root=root->next;
	}
	root = try;


	FILE * dosya_2;/*customers klasörü için bir klasör tanımladım*/
	dosya_2 = fopen("customers.txt","r");/*dosyayı okumak için açtım*/

	musteri * head;/*listeyi en başta boş olmasını atadım*/
	head = NULL;/*listeyi en başta boş olmasını atadım*/
	while(!feof(dosya_2))/*dosyadaki taranmamış eleman kalmayana kadar devam eder*/
	{
		/*bu okuma gerçekleşirken satırdaki değerler parça parça okunur.*/

		fscanf(dosya_2,"%d,%s ",&oda_no,isim);/*ilk iki değeri okur*/
		i = 0;
		while(i < 11)
		{
			fscanf(dosya_2,"%c",&bos);/*soyadı harf harf alarak okur*/
			if (bos == virgul)
			{
				soyisim[i] = '\0';
				i = 11;
			}
			else
			{
				soyisim[i]=bos;
				i += 1;
			}		
		}
		fscanf(dosya_2,"%d,",&yas);/*yas okunur*/
		i = 0;
		while(i < 7)
		{
			fscanf(dosya_2,"%c",&bos);/*cinsiyet dosyadan okunur*/
			if (bos == son)
			{
				cinsiyet[i] = '\0';
				i = 7;
			}
			else
			{
				cinsiyet[i]=bos;
				i += 1;
			}		
		}	
		head = add_customer_to_end(head,yas,isim,soyisim,cinsiyet,oda_no);/*listeye bağlanması için fonksiyona gönderilir*/
	}
	fclose(dosya_2);/*dosyayı kapttım*/

	musteri * head_2 = head;/*klasörün başını kaybetmemek için kullandım*/
	printf("\n--Customer klasöründen alınarak bağlanmış listedeki değerler--\n");
	while(head_2 != NULL)/*listedeki değerleri ekrana yazar*/
	{
		printf("%d,%s %s,%d,%s\n",head_2->oda,head_2->ad,head_2->soyad,head_2->yas,head_2->cinsiyet);
		head_2=head_2->next;
	}
	

/*BURADAN AŞAĞISI MAİNİN SONUDUR VE HAFIZADAN ALINAN YERLER SERBEST BIRAKILIR*/

	oda * iter;/*yedek olarak başı tutan bir değişken tuttum*/
	while(root != NULL)/*dosya boşalana kadar devam eder*/
	{
		iter = root;/*baş kısmı kaybolmaz her turda*/
		if (iter->next == NULL)/*tek eleman kalırsa bu koşula girer*/
		{
			root = NULL;
			free(root);/*hafızadaki yeri serbest bırakılır*/
		}
		else
		{
			while(iter->next->next != NULL)
			{
				iter = iter->next;
			}
			iter->next = NULL;/*son elemanın yeri güncellenir*/
			free(iter->next);/*hafızadaki yeri serbest bırakılır*/
		}
	}

	musteri * temp;/*yedek olarak başı tutan bir değişken tuttum*/
	while(head != NULL)/*dosya boşalana kadar devam eder*/
	{
		temp = head;/*baş kısmı kaybolmaz her turda*/
		if (temp->next == NULL)/*tek eleman kalırsa bu koşula girer*/
		{		
			free(head->ad);/*alınan her eleman için hafızadaki yeri serbest bırakılır*/
			free(head->soyad);
			free(head->cinsiyet);
			free(head);
			head = NULL;
		}
		else
		{
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}		
			free(temp->next->ad);/*alınan her eleman için hafızadaki yeri serbest bırakılır*/
			free(temp->next->soyad);
			free(temp->next->cinsiyet);
			free(temp->next);
			temp->next = NULL;/*son elemanın yeri güncellenir*/
		}
	}
	return 0;	
}

/*listeleme fonksiyonudur ve oda numarasına göre sıralı liste yapar*/
oda * add_room_to_end(oda * root ,int oda_no ,int kapasite ,int oda_kat)
{
	if (root == NULL)/*liste boş ise ilk eleman bağlamak için buraya girer*/
	{
		root = (oda *)malloc(sizeof(oda));/*yeri ayrılır*/
		root->next = NULL;/*sonraki eleman boş olarak atanır*/
		root->sayi = oda_no;
		root->kapasite = kapasite;/*atamalar yapılır*/
		root->kat = oda_kat;
		return root;/*listenin başı return edilir*/
	}
	if (root->sayi > oda_no)/*listenin başının değişme koşulu*/
	{
		oda * temp = (oda *)malloc(sizeof(oda));/*yeri ayrılır*/
		temp->sayi = oda_no;
		temp->kapasite = kapasite;
		temp->kat = oda_kat;/*atamalar yapılır*/
		temp->next = root;
		return temp;/*listenin başı return edilir*/
	}
	oda * iter = root;
	
	while(iter->next != NULL && iter->next->sayi < oda_no )/*istenilen aralığa kadar ilerletir*/
	{
		iter = iter->next;
	}

	oda * temp = (oda *)malloc(sizeof(oda));/*yeri ayrılır*/
	temp->next = iter->next;
	iter->next = temp;
	temp->sayi = oda_no;/*atamalar yapılır*/
	temp->kapasite = kapasite;
	temp->kat = oda_kat;
	return root;/*listenin başı return edilir*/
}

oda * add_room_after_room_number(oda * root)/*istenilen numaradaki odadan sonrasına oda ekleme fonksiyonu*/
{
	int oda_no ,kapasite ,oda_kat ,no_oda;
	int istenen_oda,count = 0;

	oda * temp = root;/*liste başı korunur*/

	printf("sonrasına eklenecek odanın numarasını giriniz :");
	scanf("%d",&oda_no);

	while(temp != NULL && count == 0)/*istenilen odanın olup oladığı kontrol edilir*/
	{
		if (temp->sayi == oda_no)
		{
			count = 1;
		}
		else
		{
			temp = temp->next;
		}
	}
	printf("oda no giriniz : ");
	scanf("%d",&no_oda);
	printf("kapasite giriniz : ");
	scanf("%d",&kapasite);
	printf("kat giriniz : ");
	scanf("%d",&oda_kat);	

	if (count == 0)/*listede istenilen odanın bulunmadığı koşuludur*/
	{	
		oda * iter = root;

		while(iter->next != NULL)
		{
			iter = iter->next;
		}
		iter->next = (oda *)malloc(sizeof(oda));/*yeri ayrılır*/
		iter->next->sayi = no_oda;
		iter->next->kapasite = kapasite;
		iter->next->kat = oda_kat;/*atamalar yapılır*/
		iter->next->next = NULL;
		return root;/*listenin başı return edilir*/	
	}
	else/*listede istenilen odanın bulunduğu koşuludur*/
	{
		oda * count = (oda *)malloc(sizeof(oda));/*yeri ayrılır*/
		count->next = temp->next;
		temp->next = count;
		count->sayi = no_oda;/*atamalar yapılır*/
		count->kapasite = kapasite;
		count->kat = oda_kat;
		return root;/*listenin başı return edilir*/
	}
}

oda * remove_room(oda * root)/*istenilen odanın silineceği fonksiyondur*/
{
	int sil;
	oda * temp;
	oda * iter = root;
	printf("silmek istediğiniz oda numarasını giriniz : ");
	scanf("%d",&sil);

	if (root->sayi == sil)/*silinecek eleman listenin başı ise bu koşula girer*/
	{
		temp = root;
		root = root->next;
		free(temp);/*olduğu alan serbest bırakılır*/
		return root;/*liste başı güncel return edilir*/
	}

	while(iter->next != NULL && iter->next->sayi != sil)/*silinecek adres bulunur*/
	{
		iter = iter->next;
	}
	if (iter->next == NULL)
	{
		printf("Sayi bulunamadi\n");
		return root;
	}
	/*arada ise atamalar gerçekleşir ve silinir*/
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);/*olduğu alan serbest bırakılır*/
	return root;/*liste başı güncel return edilir*/
}

oda * get_by_floor(oda * root)/*istenilen katı ekrana basan fonksiyondur*/
{
	oda * temp = root;
	int kat;
	printf("ekrana basmak istediğiniz kat numarasını giriniz : ");
	scanf("%d",&kat);

	while(temp != NULL)/*liste sonuna kadar taranır*/
	{
		if (temp->kat == kat)/*listenin anlık değeri istenilen katta ise ekrana basılır*/
		{
			printf("oda no :%d ,oda kapasitesi :%d\n",temp->sayi ,temp->kapasite);
		}
		temp = temp->next;
	}
	printf("\n");
	return root;
}

/*gelen elemanlar ile lista yapan fonksiyon*/
musteri * add_customer_to_end(musteri * root ,int yas ,char ad[] ,char soyad[] ,char cinsiyet[],int oda)
{
	if (root == NULL)/*liste boş ise bu koşula girer*/
	{
		root = (musteri *)malloc(sizeof(musteri));/*listenin bağı için yer ayrılır*/

		root->oda = oda;
		root->yas = yas;

		root->ad = (char *)malloc(sizeof(char) * (strlen(ad) + 1));
		root->soyad = (char *)malloc(sizeof(char) * (strlen(soyad) + 1));/*pointerlı ifadeler içinde yer ayrılır*/
		root->cinsiyet = (char *)malloc(sizeof(char) * (strlen(cinsiyet) + 1));

		strcpy(root->ad, ad);
		strcpy(root->soyad, soyad);/*atamalar gerçekleşir*/
		strcpy(root->cinsiyet, cinsiyet);
		root->next = NULL;/*listenin sonu boş olarak tanımlanır*/		
		return root;/*listenin başı return edilir*/
	}
	musteri * iter = root;

	while(iter->next != NULL)/*listenin sonuna eleman eklemak için listanin son elemanına kadar gider*/
	{
		iter = iter->next;/*bir sonraki bağa geçiş sağlanır*/
	}
	
	iter->next = (musteri *)malloc(sizeof(musteri));/*listenin bağı için yer ayrılır*/

	iter = iter->next;
	iter->oda = oda;
	iter->yas = yas;

	iter->ad = (char *)malloc(sizeof(char) * (strlen(ad) + 1));
	iter->soyad = (char *)malloc(sizeof(char) * (strlen(soyad) + 1));/*pointerlı ifadeler içinde yer ayrılır*/
	iter->cinsiyet = (char *)malloc(sizeof(char) * (strlen(cinsiyet) + 1));	

	strcpy(iter->ad, ad);
	strcpy(iter->soyad, soyad);/*atamalar gerçekleşir*/
	strcpy(iter->cinsiyet, cinsiyet);
	iter->next = NULL;	/*listenin sonu boş olarak tanımlanır*/
	return root;/*listenin başı return edilir*/
}