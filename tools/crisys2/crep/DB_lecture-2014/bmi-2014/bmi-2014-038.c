#include <stdio.h>

int main(void)
{
  float wei; /*体重を受け取る*/
  float hei; /*身長を受け取る*/

  printf("身長を入力してください(m):");
  scanf("%f", &hei);
  printf("体重を入力してください(kg):");
  scanf("%f", &wei);

  printf("あなたのBMIは、%fです\n", wei / (hei * hei)); /*表示するときに算出*/

  return 0;
}
