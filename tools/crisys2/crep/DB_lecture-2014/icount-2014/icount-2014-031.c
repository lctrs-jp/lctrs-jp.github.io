#include <stdio.h>

void numchecker(char b[]);

int main(void)
{
  char a[100];

  printf("数字列を入力してください。（100桁以内）\n");
  fgets(a,100,stdin);

  numchecker(a);

  return 0;
}

void numchecker(char b[])
{
  int i,j;
  int c[9];

  for(i=0;i<=9;i++)
    {
      c[i]=0;
      for(j=0;b[j] != '\0';j++)
	{
	  if(b[j] == '0'+i)
	    c[i]++;
	}
      printf("%d は %d個含まれています。\n",i,c[i]);
    }
}
