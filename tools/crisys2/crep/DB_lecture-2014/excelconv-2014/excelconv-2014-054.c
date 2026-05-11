#include<stdio.h>
#include<string.h>

int excelconv(char x[]);

int main(int len,char *a[])
{
  int i,j;
    for(i=1;i<len;i++){
    j=excelconv(a[i]);
  printf("%d\n",j);
  }
  return 0;
}

int excelconv(char x[])
{
  int i,j,k,l,n;
  n=strlen(x);
  k=0;
  for(i=0;i<n;i++){
    j=*(x+i)-64;
  for(l=n-1;l>0;l--){
    j=j*26;
      }
  k=k+j;
  n--;
    }
j=*(x+i)-64;
  k=k+j;
  return k;
}
