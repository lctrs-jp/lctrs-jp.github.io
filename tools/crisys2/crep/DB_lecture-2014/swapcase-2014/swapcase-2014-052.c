#include <stdio.h>

void swapcase(char str[]);  //入力された文字列の大文字と小文字を入れ替える。

int main(void)
{
  char s[100];

  printf("100文字以内の文字列を入力してください。\n");
  fgets(s,100,stdin);

  swapcase(s);
  printf("入力された文字列の大文字と小文字を入れ替えると、\n%s\nになります。",s);

  return 0;
}

//ASCIIコードでアルファベットが連番なのを利用して、A,aを利用して文字列を変換する。
void swapcase(char str[])
{
  int i;

  for(i=0;str[i] != '\0';i++)
    {
      if(str[i]>='a' && str[i]<='z')
	str[i]=str[i]-'a'+'A';
      else if(str[i]>='A' && str[i]<='Z')
	str[i]=str[i]-'A'+'a';
    }
}
