#include <stdio.h>

/*作成2014/10/09
  更新2014/10/16
  ** ** */

int main()
{
  //変数の宣言
  float height;
  int weight;

  //入力
  printf("身長は?(mで) ");
  scanf("%f",&height);
  printf("体重は?(kgで) ");
  scanf("%d",&weight);
  
  //表示
  printf("BMIは %f\n", weight / height / height );

  return 0;
}
