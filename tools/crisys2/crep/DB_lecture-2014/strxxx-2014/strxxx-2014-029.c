#include <stdio.h>

void mystrcpy(char to[],char from[]);//toにfromをにコピー
void mystrcat(char target[],char source[]);//targetの後尾にsourceを付加。
int mystrlen(char len[]);//lenの長さを計る
int mystrcmp(char plus[],char minus[]);
//文字列を辞書順に直して、plusが早ければ正、minusが早ければ負、等しければ0を返す。

int main()
{
  char a[101];
  char b[101];
  char cpy[101];
  char cat[201];
  int len;
  int check;

  printf("100文字以内の小文字を入れてください。\n");
  fgets(a,100,stdin);
  printf("もう一回、100文字以内の小文字を入れてください。\n");
  fgets(b,100,stdin);

  mystrcpy(cpy,a);
  printf("初めに打った文字は\n%s\nですね。\n",cpy);
  
  mystrcpy(cat,cpy);
  mystrcat(cat,b);
  printf("二つの文字列を合わせると\n%s\nになります。\n",cat);

  len=mystrlen(a);
  printf("初めに打った文字の文字数は、%d文字です。",len-1);

  check=mystrcmp(a,b);
  switch(check+1)
    {
    case 0:
      printf("辞書順では、後の文字列のほうが先に来ます。");
      break;
    case 1:
      printf("二つの文字列は同じです。");
      break;
    case 2:
      printf("辞書準では、前の文字列のほうが先に来ます。");
      break;
    }

  return 0;
}


void mystrcpy(char to[],char from[])
{
  int i;
  int fin;

  fin=mystrlen(from);

  for(i=0;i<=fin;i++)
    to[i]=from[i];
}


void mystrcat(char target[],char source[])
{
  int i;
  int fin;
  int len;

  fin=mystrlen(source);
  len=mystrlen(target);

  for(i=0;i<=fin;i++)
    target[i+len]=source[i];
}


//null文字が来るまでの文字数をカウント。
int mystrlen(char len[])
{
  int i;
  int length;

  for(i=0;;i++)
    {
      length=i;
      if(len[i]=='\0')
	break;
    }
  return length;
}


//ASCIIコードを使って順番を判断（nullは0）。
int mystrcmp(char plus[],char minus[])
{
  int i;
  int lenPlus;
  int lenMinus;
  int checker=0;

  lenPlus=mystrlen(plus);
  lenMinus=mystrlen(minus);

  for(i=0;i<lenPlus;i++)
    {
      if(plus[i]>minus[i])
	{
	  checker=-1;
	  break;
	}
      if(plus[i]<minus[i])
	{
	  checker=1;
	  break;
	}
    }
  
  if(checker==0 && lenPlus<lenMinus)
    checker=-1;    

  return checker;
}
