#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[])
{ int num=0,i=0,n,j=0,c;
  char *str=argv[1];
  
  n=strlen(str);
  for(i=0;i<n;i++){
    c=str[i]-64;
    for(j=0;j<n-i-1;j++)
      c=c*26;
    
    num=num+c;
  }
  printf("%d\n",num);
  return 0;
}  
    

