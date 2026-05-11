#include<string.h>
#include<stdio.h>
int main(void)
{
  char str[100];
  int i,k,t,a,c[27],max,m;

  for (a=0;a<27;a++)
    {
     c[a]=0;
   }


  printf("文字列を入力してください");
  fgets(str,100,stdin);
  t=strlen(str);
  for (k=0;k<26;k++)
    {
      for (i=0;i<t;i++)
	{
	  if(str[i]==k+97)
	    {
              c[k]=c[k]+1;
	    }
	  else if(str[i]==k+65)
	    { 
              c[k]=c[k]+1;
	    }
	}
    }
  /*  for(k=0;k<27;k++)
      printf("%dは%d\n",k,c[k]);*/

  max=0;
  m=0;
  for (k=0;k<27;k++)
    {  if(max<c[k])
	{   max=c[k];
      
	}

    }
  printf("%d",m);

  printf("最頻出文字は%s \n %d回",m,max);
  return 0;
}
