#include <stdio.h>

int main(void)
{
  int i,j,end, num1[10];
  char num[100];

  printf("数字列を入力して下さい(長さ100以下)：");
  gets(num);
  for (i=0; i < 100; i++)
    if (num[i] == 0) {
      end = i;
      break;
    }

  for (i = 0; i < 10; i++) {
    num1[i] = 0;
    for (j = 0; j < end; j++) {
      if (num[j] == i + 48)
        num1[i] = num1[i] + 1;
    }
  }

  for (i = 0; i < 10; i++)
    printf("%d は %d 個あります。\n", i, num1[i]);

  return 0;
}
