#include<string.h>
#include<stdio.h>
int main (void)
{
  int i,k,sum=0,t,a[10];
  char str[50]; 
  /* printf("文字数は？");
     scanf("%d",&t);*/

  printf("数を入力してください。");
  gets(str);
  t=strlen(str);
  for(i=0;i<10;i++)
    {
      for(k=0;k<t;k++)
	{
	  if(str[k]==i+48)
	    sum=sum+1;
	}
      printf("%dは%d回\n",i,sum);
      sum=0;    
}
  return 0;
}
