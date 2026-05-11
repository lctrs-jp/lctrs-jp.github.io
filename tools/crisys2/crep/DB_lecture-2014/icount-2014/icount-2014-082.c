#include<stdio.h>

void search(char str[],int num[]);

int main(void){
  char str[100];
  int num[10]; 
  int i;
  printf("文字列を入力してください。\n");
  scanf("%s",&str);
  search(str,num);
  for (i = 0; i <10; i++)
    {
    printf("%dの数は%d個です。\n",i,num[i]);
  }
  return 0;
}

void search(char str[],int num[]){
  int i,j;
  
  for(i=0;i<10;i++){ 
    num[i] = 0;
    for(j=0;str[j]!='\0';j++)
      if(str[j] == i+48){
	num[i]++;
      }
  }
        
  return ;
    
}
