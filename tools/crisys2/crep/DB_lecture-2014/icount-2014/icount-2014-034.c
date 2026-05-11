#include <stdio.h>

int main(void)
{
  char str[100];
  int i, n[10], j;

  printf("数字列を入力してください(長さ100以下) : ");
  gets(str);

  for (j = 0; j <= 9; j++)  {

    n[j] = 0;

  for(i = 0; str[i] != '\0'; i++) {
    if('0' <= str[i] && str[i] <= '9')
      n[str[i] - '0']++;
  }
    printf(" %d は %d 個含まれています\n", j, n[j]);   
  }

  return 0;
}
