#include<stdio.h>



int main()
{

  double h,w,B;


  printf("あなたの身長を入力してください。[cm]=");
  scanf("%lf",&h);

  printf("あなたの体重を入力してください。[kg]=");
  scanf("%lf",&w);

  B=10000*w/(h*h);
  printf("あなたのBMIは%f[kg/m^2]\n",B);

  return 0;
}
