#include<stdio.h>
#include<string.h>
int saiki(char str[]);
int main(int argc, char *argv[])
{
  printf("%d",saiki(argv[1]));
  return 0;
}
int saiki(char str[])
{
  int i,sum,j;
  j=strlen(str)-1;
  sum=0;
  for(i=0;i<=j;i++)
    sum=26*sum+*(str+i)-'A'+1;
  return sum;
        
}
