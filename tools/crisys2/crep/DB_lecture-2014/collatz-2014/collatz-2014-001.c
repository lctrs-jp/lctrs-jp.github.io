#include <stdio.h>

int main(void)
{
  int num;

  printf("数字を入力してください(２以上３×（２の５３乗）以下）: ");
  scanf("%d", &num);

  while (num != 1){
    if (num % 2 != 0)  //偶奇の判定部分
      num = (num * 3) + 1;
    else
      num = num / 2;

    printf ("-> %d\n", &num);
  }
  printf ("よって１になった");
  return 0;
}