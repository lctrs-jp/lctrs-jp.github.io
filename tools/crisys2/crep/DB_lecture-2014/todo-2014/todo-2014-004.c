#include <stdio.h>

int main()
{
  int x[50], y[50], z[50], i=0, j=0;
  char str[80][80];

  for(i=0;x[i]!=0 && y[i]!=0 && z[i]!=0;i++)
    {
      printf("何をするのか入力してください\n");
      fgets(str[i],80,stdin);
      printf("年月日を入力してください(終了は0を入力)\n");
      scanf("%d/%d/%d", &x[i], &y[i], &z[i]);
    }

  for(j=0;j<=i;j++)
    {
    printf("%d/%d/%d", x[i], y[i], z[i]);
    printf(str[i]);
    }
  return 0;
}