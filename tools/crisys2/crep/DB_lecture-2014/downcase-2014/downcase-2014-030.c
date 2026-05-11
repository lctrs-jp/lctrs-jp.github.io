#include <stdio.h>

void downcase(char str[]);

int main(void)
{
  char a[100];

  printf("100文字以内の文字列を入力してください。");
  fgets(a,100,stdin);

  downcase(a);
  printf("その文字列の大文字を小文字に変換すると、\n%s\nになります。",a);

  return 0;
}

void downcase(char str[])
{
  int i;

  for(i=0;str[i] != '\0';i++)
    {
      if(str[i] >='A' && str[i] <='Z')
	str[i]=str[i]-'A'+'a';
    }
}
