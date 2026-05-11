#include <stdio.h>

void upcase();

int main()
{
  char str[80];

  printf("80文字以内で文字列を入力してください\n");
  fgets(str,80,stdin);

  upcase(str[80]);//入力した文字列をupcase()で処理する

  return 0;
}

//upcaseの中身
void upcase(char str[])
{
  int i;

  for( i=0 ; str[i] != '\0'; i++)
    {
      if('a' <= str[i] && str[i] <= 'z')//小文字だった場合は大文字-小文字の差分を足す
	{
	  str[i] = str[i]+('A'-'a');
	}}
  return ;
}
