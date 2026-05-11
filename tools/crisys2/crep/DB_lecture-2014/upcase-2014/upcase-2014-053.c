#include <stdio.h>

void upcase(char str[]); //文字列の小文字を大文字に変換する。

int main(void)
{
  char s[100];

  printf("100文字以内の文字列を入力してください。\n");
  fgets(s,100,stdin);

  upcase(s);

  printf("入力された文字列の小文字を大文字に直すと、\n%s\nになります。",s);

  return 0;
}

//ASCIIコードのアルファベットが連番なのを利用して、A,aを使って文字列を変換する。
void upcase(char str[])
{
  int i;

  for(i=0;str[i] != '\0';i++)
    if(str[i]>='a' && str[i]<='z')
      str[i]=str[i]-'a'+'A';
}
