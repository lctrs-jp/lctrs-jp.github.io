#include <stdio.h>
float bmi(float t,float u);

float main()
{
  float t ;
  float u ;
  printf("身長[m]を入力してください") ;
  scanf("%f",&t);
  printf("体重[kg]を入力してください") ;
  scanf("%f", &u);
  float v;
  v=bmi(t,u);  

  if(v<18.5)
  printf("あなたのBMIは %f (やせ)\n",v);
  if(v>=18.5 && v<25)
  printf("あなたのBMIは %f (標準)\n",v);
  if(v>=25 && v<30)
  printf("あなたのBMIは %f (肥満)\n",v);
  if(v>=30)
  printf("あなたのBMIは %f (高度肥満)\n",v);
  return 0;
}

float bmi(float t,float u)
{
  return u/t/t;
}
