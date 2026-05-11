#include <stdio.h>

void reverse(char trg[],char str[]);

int main(void)
{
  char a[100];
  char b[100];

  printf("100文字以内の文字列を入力してください。");
  fgets(a,100,stdin);

  reverse(b,a);
  printf("その文字列を逆から読むと、\n%s\nになります。",b);

  return 0;
}

void reverse(char trg[],char str[])
{
  int i,j;
  int len=0;

  for(i=0;str[i] != '\0';i++)
    len++;

  for(j=0;j<len;j++)
    trg[j]=str[len-1-j];
}
