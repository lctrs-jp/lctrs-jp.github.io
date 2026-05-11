#include<stdio.h>

int one ();
int two ();

int main(void)
{

  double w,h,B;

 h= one();
 w= two();
 
  B=10000*w/(h*h);

  if(B < 18.5)
  printf("あなたのBMIは%f[kg/m^2]（やせ）\n",B);

  if(18.5 <= B && B < 25)
    printf("あなたのBMIは%f[kg/m^2]（標準）\n",B);

  if(25 <= B && B < 30)
    printf("あなたのBMIは%f[kg/m^2]（肥満）\n",B);

  if(30 <= B)
    printf("あなたのBMIは%f[kg/m^2]（高度肥満）\n",B);



  return 0;
}


int one()
{
  double h;

  printf("あなたの身長を入力してください。[cm]=");
  scanf("%lf",&h);
  return h;
}

int two()
{
  double w;

  printf("あなたの体重を入力してください。[kg]=");
  scanf("%lf",&w);
  return w;
}
