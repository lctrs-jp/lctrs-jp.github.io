#include <stdio.h>

int mostword(char str[]); //入力された文字列の中で最も多い文字を返す。

int main(void)
{
  char s[100];
  char most;
  int a;

  printf("100文字以内の文字列を入力してください。\n");
  fgets(s,100,stdin);

  a=mostword(s);
  most=a;
  
  printf("入力された文字列の中で最も多い文字は、\n%s\nです。",most);

  return 0;
}

int mostword(char str[])
{
  int alp[26]; //それぞれのアルファベットのかず。
  int m; //最大のアルファベット。
  int i,j,k;
  int p;

  for(i=0;i<26;i++)
    alp[i]=0;

  for(j=0;str[j] != '\0';j++)
    {
      if(str[j]>='A' && str[j]<='Z')
	{
	  p=str[j]-'A';
	  alp[p]++;
	}
      else if(str[j]>='a' && str[j]<='z')
	{
	  p=str[j]-'a';
	  alp[p]++;
	}
    }

  m='a';
  //mに最大のアルファベットを入れる。
  for(k=1;k<26;k++)
    if(alp[k]>alp[m-'a'])
      m='a'+k;
  
  return m;
}
