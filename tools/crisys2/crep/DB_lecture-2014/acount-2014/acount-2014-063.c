#include<stdio.h>

void search(char str[],int num[]);

int main(void){
  char str[100];
  int num[10];
  int i;
  int max;
  printf("文字列を入力してください。\n");
  scanf("%s",&str);
  search(str,num);
  
  {
      printf("最頻出の文字数は%dで、%d個です。\n",max,num[i]);
    }
    return 0;
}

void search(char str[],int num[]){
   int i,j,k,max;
  
  for(i=1;i>=65 && i<90 && i>=97 && i<122;i++){
    num[i] = 0;
       for(j=0;str[j]!='\0';j++)
	 if(str[j] == i){
	   num[i]++;
	 }
  }
  if(num[i] > num[i-1])
    {  max = i;
    }
  return ;
}
