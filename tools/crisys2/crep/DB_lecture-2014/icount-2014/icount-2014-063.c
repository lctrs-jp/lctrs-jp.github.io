#include<stdio.h>

int main(void){
  int i,j,count;
  char fig = '0';
  char num[20];
  printf("数字の列を入力してください\n");
  scanf("%20s",num);

  for(i = 0;i < 10;i++){
    count = 0;
    for(j = 0;num[j];j++){
      if(num[j] == fig)
	count++;
   }
    printf("%d は %d個含まれています\n",i,count);
    fig++;
  }
  return 0;
}
