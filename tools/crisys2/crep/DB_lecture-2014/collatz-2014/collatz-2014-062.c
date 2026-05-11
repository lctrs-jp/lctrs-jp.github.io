#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void)
{
  int n;
  printf(" 数値を入力してください: ");
  scanf("%d", &n);

  while(n != 1){
    if(n % 2)
      n = n * 3 + 1;
    else
      n = n / 2;
    printf("最初の文字は %d になりました!\n", n);
  }
  return;
}
