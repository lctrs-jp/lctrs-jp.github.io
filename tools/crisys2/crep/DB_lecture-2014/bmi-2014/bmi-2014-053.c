#include <stdio.h>

int main()
{
  int w;//体重
  float l;//身長
  printf("体重を入力(kg)\n");
  scanf("%d",&w);
  printf("身長を入力(m)\n");
  scanf("%f",&l);
  float b = w/(l*l);//BMI
  printf("BMI=%f\n",b);//BMI=体重/(身長*身長)
  return 0;
}
