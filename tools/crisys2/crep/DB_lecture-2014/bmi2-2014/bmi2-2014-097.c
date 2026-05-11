#include<stdio.h>

double bmicl(double w,double h);

int  main ()
{
  double w,h,k;
  printf("身長を入力してください：");
  scanf("%lf",&h);
  printf("体重を入力してください：");
  scanf("%lf",&w);
  k=bmicl(w,h);  
  printf("あなたのBMIは%lfです",k);
  if(k>=30)
    printf("高肥満度");
  else if(k>=25)
    printf("肥満");
  else if(k>=18.5)
    printf("標準");
  else 
    printf("やせ");

 return 0;
}


double bmicl(double w,double h)
{ 
  return w/(h*h);
}
