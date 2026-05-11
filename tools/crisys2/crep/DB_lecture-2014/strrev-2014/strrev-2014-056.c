#include <stdio.h>
void reverse(char trg[], char src[]);

int main(void)
{
  char str1[100], str2[100];

  printf("文字を入力してください\n");
  fgets(str2, 100, stdin);

  reverse(str1, str2);

  printf("%s", str1);

  return 0;
}

void reverse(char trg[], char src[])
{
  int i, x, y;

  for(i = 0; src[i] != '\0'; i++)
    trg[i] = src[i];

  for(x = 0; src[x] != '\0'; x++)
    ;

  for(y = 0; y < x; y++)
    src[y] = trg[x - y -1];
  
  for(i = 0; src[i] != '\0'; i++)
    trg[i] = src[i];
}    
