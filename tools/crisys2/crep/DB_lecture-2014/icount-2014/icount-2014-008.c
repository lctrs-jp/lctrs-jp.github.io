#include<stdio.h>
#include<string.h>

int main(void)
{

  int i,t ;
  char n[101];
  int count[10]={0,0,0,0,0,0,0,0,0};

  printf("数字列を入力しなさい。（長さ百以下）:");
  scanf("%s",&n);

  for (i = 0 ; i < strlen(n) ; i++){
    for (t=0;t<=9;t++){
      if (t+48 == n[i])
	count[t]++;
    }
  }

  for (i=0;i<=9;i++){
    printf("%dは%d個含まれております。\n",i ,count[i]);
  }
  return 0;
}
