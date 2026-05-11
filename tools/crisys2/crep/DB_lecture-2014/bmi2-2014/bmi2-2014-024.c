#include <stdio.h>
int bmi(int a ,float b);/*bmiの関数の宣言*/
int main()
{
  float height;
  int weight;
  printf("身長(m)を入力してください\n" );
  scanf("%f", &height );
  printf("体重(kg)を入力してください\n");
  scanf("%d", &weight );
  if(bmi(weight,height)<18.5){
    printf("あなたのBMIは%fです。(やせ)\n",bmi(weight,height));
  }
  else if(bmi(weight,height)<25&&bmi(weight,height)>=18.5){
    printf("あなたのBMIは%fです。(標準)\n",bmi(weight,height));
 }
  else if(bmi(weight,height)<30&&bmi(weight,height)>=25){
    printf("あなたのBMIは%fです。(肥満)\n",bmi(weight,height));
      }
  else {
    printf("あなたのBMIは%fです。(高度肥満)\n",bmi(weight,height));
  return 0;
  }
}
int bmi(int a , float b)/*bmiの関数本体*/　　　　　　　
{
  float bm;
  bm = a / ( b * b);
  return bm;
}
