#include<stdio.h>
#include<string.h>
#include<math.h>

int excelconv(char *a, int i);

int main()
{
  char str[6];
  int ans;
  int len;

  printf("アルファベットを大文字で５桁まで入力してください: ");
  gets(str);

  len = strlen(str);

  ans = excelconv(str, len-1);
  printf("%d\n", ans);

  return 0;
}

int excelconv(char *a, int i)
{
  if(i == 0)
    return *a - 64;
  else
    return 26 * excelconv(a, i-1) + (*(a+i) - 64);
}
