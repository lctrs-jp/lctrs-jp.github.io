#include<stdio.h>
int main()
{
  int n;
  printf("数字を入力してください");
  scanf("%d",&n);
 
  while(n>1){

  if(n%2==0)
    n=n/2;

  else
   n=n*3+1;

  printf("%d",n);

  if(n!=1)
  printf("->");
 }

  printf("\n");

  return;
}
