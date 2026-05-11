#include<stdio.h>

int main()
{int k,i,j,n[10];
  char  num[101];
  for(k=0;k!=10;k++)
    n[k]=0;

printf("数字列を入力してください（100以下）:");
 scanf("%s",num); 
 for(i=0;num[i]!='\0';i++){
   k=num[i]-48;
   n[k]++;}
 for(i=0;i!=10;i++)
{






 printf("%dは%d個含まれています。\n",i,n[i]);}


   return;}

