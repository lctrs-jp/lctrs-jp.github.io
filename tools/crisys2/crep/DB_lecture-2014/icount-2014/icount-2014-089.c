#include <stdio.h>
#include <string.h>

int main()
{
  int j, t;
  char i[100];
  int count[10]={0,0,0,0,0,0,0,0,0,0};

  printf("数字列を入力してください(長さ100以下) : ");
  scanf("%s",&i);

  for(t = 0; t < strlen(i); t++)
    {
      for(j = 0; j <= 9; j++)
        {
          if(j+48 == i[t])
            count[j]++;
        }
    }

  for(j = 0; j < 10; j++)
    {
      printf("%d は %d個含まれています。\n", j, count[j]);
    }

  return 0;
}
