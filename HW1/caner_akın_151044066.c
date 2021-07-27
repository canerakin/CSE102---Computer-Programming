/*Caner AKIN
151044066*/
#include <stdio.h>
#include <math.h> /*pow ve sqrt işlemleri için çağırdığım kütüphane*/
#define PI 3.14 /*pi yi 3.14 olarak heryerde tanımlamış oldum*/
           /*gerekli olan ve kullandığım tüm fonksiyonları tanımladım*/
double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square (int side);
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square);

int main()/* mani fonksiyonunda sadece display fonsiyonunu çağırdığım için sadece onun değerlerini tanımladım*/
{ 
  double largest_circle;
  double largest_square;
  double smallest_circle;
  double smallest_square;
  display_results( largest_circle, largest_square, smallest_circle, smallest_square);/*işlemlerin gerçekleştiği fonksiyonu çağırdım*/
  return 0;
}

double circle_area(double radius)/*bu fonsiyon çağırıldığı zaman verilen yarıçap ile dairenin alanını hesaplar*/
{
  double alan;
  alan = PI * (double) pow(radius , 2); /*işlemde virgüllü sonuç çıkacağı için değerleri double tanımladım*/
  return alan;
}

double calc_hypotenuse(int side1, int side2)/*bir dik üçgenin kenarı aynı zamanda dairenin hipotenüsüdür ve bu fonsiyon dairenin hipotenüsünü hesaplar*/
{
  double hipotens;
  hipotens = (double)sqrt(side1 * side1 + side2 * side2);/*işlemde virgüllü sonuç çıkacağı için değerleri double tanımladım*/
  return hipotens;
}

double calc_radius_of_smallest_circle(int side1, int side2)/*dikdörtgeni çevreleyen dairenin yarıçapını bulan fonksiyonundur.*/
{
    double yaricap;
    yaricap = calc_hypotenuse(side1 , side2) / 2;/*işlemde virgüllü sonuç çıkacağı için değerleri double tanımladım*/
    return yaricap;
}

double calc_radius_of_largest_circle(int side1, int side2)/*dikdörtgenin içindeki dairenin yarıçapını bulan fonksiyon*/
{   
    double kucuk_daire_yaricap;
    kucuk_daire_yaricap = side1 / 2;/*dairenin çapı zaten küçük kenardır.bu yüzden direk 2 ye böldüm*/
    return kucuk_daire_yaricap;
}

double calc_area_of_smallest_circle(int side1, int side2)/*çevreleyen dairenin alanını bulan fonsiyon*/
{
    double smallest_circle;
    double yaricap;
    yaricap = calc_radius_of_smallest_circle( side1, side2);/*işlemde virgüllü sonuç çıkacağı için değerleri double tanımladım*/
    smallest_circle = circle_area(yaricap); /*yarıçapı bulduktan sonra alan hesaplayan fonksiyona göndererek alanı buldum*/
    return smallest_circle;
}

double calc_area_of_largest_circle(int side1, int side2)/*içindeki dairenin alanını hesaplayan fonsiyon*/
{
    double largest_circle;
    double yaricap = (double)side1 / 2; /*işlemde virgüllü sonuç çıkacağı için değerleri double tanımladım*/
    largest_circle = circle_area(yaricap);/*yarıçapı bulduktan sonra alan hesaplayan fonksiyona göndererek alanı buldum*/
    return largest_circle;
}

double calc_area_of_smallest_square(int side1, int side2)/*çevreleyen karenin alanını bulmak için kullanılan fonsiyondur*/
{
    int smallest_square;
    smallest_square = calc_area_of_square(side2);/*büyük kenarı kare alanı hesaplayan fonsiyona göndererek alan bulunur*/
    return smallest_square;
}

double calc_area_of_largest_square(int side1, int side2)/*içindeki karenin alanını bulan fonsiyondur*/
{
    int largest_square;
    largest_square = calc_area_of_square(side1);/*alanını bulurken dikdörtgenin küçük kenarı zaten karenin bir kenarıdır*/
    return largest_square; 
}

double calc_area_of_square (int side)/*karenin alanını hesaplayan fonksiyondur*/
{
    int alan;
    alan = side * side; /*işlemde virgüllü sonuç çıkacağı için değerleri double tanımladım*/
    return alan;
}



void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square)/*kenarların alındığı hesaplanan alanları ekrana yazan fonsiyondur*/
{
  int kenar1 = 0 , kenar2 = 0 ,side1 ,side2;

  /*istenilen pozitif ve birbirinden farklı iki kenardır ve kenarların istenilen değerler olduğunu kontrol etmek için while kullandım*/
  /*aynı zamanda değerler doğru girildiği tüm durumlarda küçük olan değer side1 büyük olan ise side2 ye atanacaktır.*/
  while(kenar1 == kenar2)/*sayılar eşit olduğu sürece döngü döner*/
  { 
    printf("kenarları tam sayı olan bir dikdörtgenin kenarlarını giriniz");
    printf("\nkenar1:");/*ilk kenarı kullanıcıdan ister*/
    scanf("%d" , &kenar1);
    printf("\nkenar2:");/*ikinci kenarı kullanıcıdan ister*/
    scanf("%d" , &kenar2);
    
    if (kenar1 == kenar2)/*kullanıcı eşit kenarlar girerse sistem başa döner*/
    {
      printf("eşit kenarlar girdiniz\n");
    }   
    else if (kenar1 <= 0 || kenar2 <= 0)/*kullanıcı bir kenarı 0  veya - girerse sistem başa döner*/
    {
      printf("0 veya - değer girdiniz\n");
      kenar2 = kenar1;/*sistem başa dönsün diye eşitlik verdim*/
    }
    else if (kenar1 < kenar2)/*ilk girdinin ikinci girdiden küçük olduğu durumlar*/
    {
      side1 = kenar1;/*ilk girdi side1 olur*/
      side2 = kenar2;/*ikinci girdi side2 olur*/
    }
    else if (kenar1 > kenar2)/*ilk girdi ikinci girdiden büyük olduğu durumlar*/
    {
      side1 = kenar2;/*ilk girdi side2 olur*/
      side2 = kenar1;/*ikinci girdi side1 olur*/
    }
  }

  largest_circle = calc_area_of_largest_circle( side1, side2);/*küçük dairenin alanını atadım*/
  largest_square = calc_area_of_largest_square( side1, side2);/*küçük karenin alanını atadım*/
  smallest_circle = calc_area_of_smallest_circle( side1, side2);/*büyük dairenin alanını atadım*/
  smallest_square = calc_area_of_smallest_square( side1, side2);/*büyük karenin alanını atadım*/

  printf("The area of the largest circle that fits inside a rectangle:         %.2lf\n", largest_circle);/*küçük dairenin alanını ekrana yazdım*/
  printf("The area of the largest square that fits inside a rectangle:         %.2lf\n", largest_square);/*küçük karenin alanını ekrana yazdım*/
  printf("The area of the smallest circle that surrounds the same rectangle:   %.2lf\n", smallest_circle);/*büyük dairenin alanını ekrana yazdım*/
  printf("the area of the smallest square that surrounds the same rectangle:   %.2lf\n", smallest_square);/*büyük karenin alanını ekrana yazdım*/

}
