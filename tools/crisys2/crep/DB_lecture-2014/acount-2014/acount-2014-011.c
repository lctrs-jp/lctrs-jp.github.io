#include<stdio.h>
#include<string.h>

void a_count(char al[],int t,int max);

int main(void)
{
  int a,m;
  char item[101];

  printf("アルファベットを入力してください:\n");
  scanf("%s",&item);

  a_count(item,a,m);

  printf("最も多いものは%sで、%d個です。",a+65,m);

  return 0;

}

void a_count(char al[],int t,int max)
{

  int i,cou[26];
  max=0;
  for(i=0;i<26;i++) cou[i]=0;

  for (i = 0 ; i < strlen(al) ; i++){
    for (t=0;t<26;t++){
      if (t+65 == al[i] || t+97 == al[i] )
	cou[t]++;
    }
  }

  for(t=0;t<26;t++){
    if(max<cou[t])
      max=cou[t];
  }

}
