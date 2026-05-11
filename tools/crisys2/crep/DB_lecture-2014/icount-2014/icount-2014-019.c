#include<stdio.h>
int main(void)
{
  char str[100];
  int count[10];
  int num,i,j;
 
  for(i=0;i<10;i++){
    count[i]=0;
  }

  printf("数を入力してください:");
  scanf("%s",str);
  for(i=0;str[i];i++){
    for(j=48;j<=57;j++){
      if(str[i]==j){
	count[j-48]+=1;
      }
    }
  }

  for(num=0;num<=9;num++)
    printf("%dは%d個含まれています\n",num,count[num]);

  return 0;

}
