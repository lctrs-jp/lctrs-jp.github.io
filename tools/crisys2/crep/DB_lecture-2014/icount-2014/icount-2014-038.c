#include<stdio.h>

int main()
{
  int k; 
 int i,j;
 char s[100],count[10];
  printf("数字列を入力してください\n");
  fgets(s,100,stdin);

  for(k=0;k<=9;k++){
      count[k]=0;
  }
  for(i=0;s[i]!='\0';i++){
    for(j=0;j<=9;j++)
      if(s[i]==j+48){count[j]++;}
      else continue;
  }   
 {
   for(j=0;j<=9;j++)

    printf("%dは%d個含まれています\n",j,count[j]);
    
  }  

    return 0;
}
