#include <stdio.h>
#include <string.h>

int main(void)

{
  char a[101];
  int q,v,max,s,t,i,cnt[30];

  for(t=0;t<=30;t++){
    cnt[t]=0;
  }

  printf("１００文字以内で文字を入力してください \n");
  scanf("%s",a);

  for(s=0;s<=strlen(a);s++){
    for(t=0;t<=30;t++){
      if(a[s]==t+65||a[s]==t+97)
	cnt[t]++;
    }
  }
  max=0;
  v=0;
   for(t=0;t<=30;t++){
    if(cnt[t]>max){
      max=cnt[t];
      v=t;
    }
  }

    printf("最も出現回数の多い文字は%cでその回数は%d回です。\n",v+97,max);

  return 0;
}
