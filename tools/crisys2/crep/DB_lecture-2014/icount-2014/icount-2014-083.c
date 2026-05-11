#include <stdio.h>
#include <string.h>

int main(void)
{
  int i,t,n,s,cnt[10];
  char a[100];

  for(i=0;i<=10;i++)
    cnt[i]=0; 

  printf("１００文字以内で文字を入力してください。");
  scanf("%s",a);

  n=strlen(a);

  for(i=0;i<=9;i++){
    for(t=0;t<=n;t++){
      if(i+48==a[t]){
	  cnt[i]++;
      }
    }
  }

  for(i=0;i<=9;i++)
  printf("%dは%d個含まれています。\n",i,cnt[i]);

  return 0;
}
