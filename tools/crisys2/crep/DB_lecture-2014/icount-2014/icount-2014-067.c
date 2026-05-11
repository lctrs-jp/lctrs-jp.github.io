#include <stdio.h>
#include <string.h>
int main(void)
{
  char number[101];
  int a, b, t;

  printf("数字列を入力してください（長さ100以下）:");
  scanf("%s", number);

  for(a = 0; a < 10; a++)
    {
      t = 0;
      for(b = 0; b < strlen(number); b++)
	if(number[b] == a + 48)
	  t = t + 1;
      printf("%d は %d 個含まれています.\n", a, t);
    }
  return;
}
