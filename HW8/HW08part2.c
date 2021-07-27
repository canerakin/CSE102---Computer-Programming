#include <stdio.h>/*standar input output kütüphanesini çağırdım*/

int find_result(int number1,int number2,char operation);/*üç işlemi yapıp return eden bir fonksiyon tanımladım*/
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);/*işlemleri bulacak olan fonksiyonu tanımladım*/

int main()
{
	int arr[] = {25, 12, 6, 10, 32, 8};	/*kullanılacak sayıları arraye atadım*/
	int expected_val = 44;/*işlemler sonucu istenen değeri atadım*/
	int arr_len = 6;/*arrayin uzunluğunu atadım*/
	char operations[arr_len - 1];/**/
	int current = 0;/*başlangıç olarak 0 dan başlar*/
	int cursor = 1,i ; /*son noktanın çarpım işlemine girebilmesi için 1 diye tanımladım*/

	for (i = 0; i < arr_len - 1; ++i)
	{
		operations[i] = ' ';/*n-1 tane boşluk elemanlı bir array doldurdum*/
		cursor = cursor * 3;/*son noktanın sayısını buldum*/
	}

	find_operations(arr ,expected_val ,operations ,arr_len ,cursor ,current);/*işlemleri bulacak olan fonksiyonu çağırdım*/
	printf("\n%s\n",operations);/*return olarak dönen işlem sırasını print eder*/
	return 0;
}

int find_result(int number1,int number2,char operation)/*üç işlemi yapıp return eden fonksiyon */
{
	if (operation == '+')/*işlem + ise buraya girer ve sayıları toplar*/
	{
		return number1 + number2;
	}
	else if (operation == '-')/*işlem - ise buraya girer ve çıkarma işlemini gerçekleştirir*/
	{
		return number1 - number2;
	}
	else if (operation == '*')/*işlem * ise buraya girer ve çarpım işlemini gerçekleştirir*/
	{
		return number1 * number2;
	}
}

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current)/*işlemleri bulacak olan fonksiyon*/
{
	int genel_toplam = 0 ,i ,bolme;
	char krktr[3] = {'+','-','*'};/*genel işlemleri bir arraye atadım*/

	if (current == cursor)/*bulunamazsa en son çıkabilmesi için gerekli koşul*/
	{
		printf("\nDo not find the number\n");
		for (i = 0; i < arr_len - 1; ++i)
		{
			operations[i] = ' ';/*n-1 tane boşluk elemanlı bir array doldurdum*/
		}		
		return operations;
	}
	i = 0;
	bolme = cursor / 3;/*bölmenin doğru gerçekleştirilmesi için gerekli atama*/
	operations[i] = krktr[(current/bolme)%3];/*ilk iki sayının işlemini bulur*/
	genel_toplam = find_result(arr[i],arr[i+1],operations[i]);/*ilk iki sayıyı işleme sokar*/

	for (i = 2; i < arr_len ; ++i)/*ilk iki sayı dışında geriye kalan sayılarda burada işleme girer*/
	{
		bolme = bolme / 3;/*bölmenin doğru gerçekleştirilmesi için gerekli atama*/
		operations[i-1] = krktr[(current/bolme)%3];/*sıradaki sayıdan önceki işlemi bulur*/
		genel_toplam = find_result(genel_toplam,arr[i],operations[i-1]);/*sıradaki sayı ile işlemi gerçekleştirir*/
	}

	if (genel_toplam == expected_val)/*istenilen değeri bulan bir işlem gerçekleşmiş ise buraya girer ve recursive son bulur*/
	{
		printf("Find the number\n");
		return operations;
	}
	return find_operations(arr ,expected_val ,operations ,arr_len ,cursor ,current + 1);/*bir işlem sırası uymuyorsa sıranın değişmesi için recursive ile yeni bir döngü sağlanır*/
}