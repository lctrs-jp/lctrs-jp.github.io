#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
  char *str=argv[1];
  int i,j,k,l,answer;
  for(i=0;i < strlen(str);i++){
    j=str[i]-64;
    l=1;
    for(k=strlen(str)-i;k>1;k--)
      l=l*26;
      answer=answer+l*j;
  }
      printf("%d\n",answer);

  
  return 0;
}

