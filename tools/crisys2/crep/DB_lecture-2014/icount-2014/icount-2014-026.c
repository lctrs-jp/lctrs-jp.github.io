#include<stdio.h>
#include<string.h>

void sss(char trg[])
{
  int i,k,j,count[10]={0};
  for(i=0;i<strlen(trg);i++){
    for(k=0;k<10;k++){
      if(trg[i]==48+k)
	count[k]++;}
  }

   for(j=0;j<=9;j++)
     printf("%dは%d個含まれています.\n",j,count[j]);
  
}

int main()
{
  char trg[100];
  printf("文字列を入力してください（長さ100以下）:");
  scanf("%s",trg);
  sss(trg);

  return 0;
}
