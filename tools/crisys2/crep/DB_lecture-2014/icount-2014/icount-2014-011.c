#include<stdio.h>
#include<string.h>

int main(void)
{
  int num,i,j,k;
  char str[101];
  
  printf("数字列を入力して下さい(長さ100以下):");
  fgets(str,101,stdin);
  k=strlen(str);
 
  for(num=0;num<10;num++){
    j=0;

    for(i=0;i<k;i++){
      
      if((int)str[i]==num+48)
        j=j+1;
      else
	;
    }

    printf("%dは%d個含まれています.\n",num,j);

  }
 return 0; 
 }
