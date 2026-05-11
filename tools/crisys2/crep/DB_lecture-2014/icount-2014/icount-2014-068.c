#include <stdio.h>

int main(void)
{
  char imp[101];
  int cnt[10];
  int len,i,j;
  char a;

  printf("数字列を入力してください（長さ１００以下）： ");
  gets(imp);

  for(i=0;i<=9;i++)
   cnt[i]=0;

  for(len=0;imp[len]!='\0';len++);

    for(i=0;i<=len-1;i++)
    {
      a='0';
      for(j=0;j<=9;j++)
	{
           if (imp[i]==a)
	     cnt[j]++;
	   a=a+1;
	}
    }

    for(i=0;i<=9;i++)
    printf("%d は %d個含まれています。\n",i,cnt[i]);
  
  return 0;
}
