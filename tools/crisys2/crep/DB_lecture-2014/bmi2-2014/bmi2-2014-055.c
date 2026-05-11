#include<stdio.h>
double w,h;
int BMIhantei();
int main()
{
  printf("身長をｍ単位で入力してみるといいかもしれません");
  scanf("%lf",&h);
  printf("体重を㎏単位で入力することをおすすめします");
  scanf("%lf",&w);
  BMIhantei();
  return 0;
}
int BMIhantei()
{
  if(w/(h*h) >= 30)
    {printf("高肥満度");
      printf("ひどい肥満ですね");};
  if(w/(h*h) <30 && w/(h*h) >=25)
    {printf("肥満");
      printf("肥満気味ですなあ");};
  if(w/(h*h)<25 && w/(h*h) >= 18.5)
    {printf("標準");
      printf("ふつうですね");};
  if(w/(h*h)<18.5)
    { printf("痩せ");
      printf("もう少し食べてはいかがです？");};
}
