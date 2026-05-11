#include<stdio.h>
#include<string.h>

int main()
{
  int i,k,j,max=0,count[30];
  char str[100],maxc;

  for(i=0;i<30;i++)
    count[i]=0;

  printf("調べたい文字列を入力してください(長さ99以下)\n");
  scanf("%s",str);

  for(i=0;i<strlen(str);i++)
    for(k=0;k<='Z'-65;k++){
      if(str[i]==65+k)
	count[k]++;
     else if(str[i]==97+k)
	count[k]++;
  }

  for(i=0;i<30;i++)
    if(max<count[i]){
      max=count[i];
      maxc=i+65;
  }

  printf("最も出現回数が多い文字は %c で %d 回です.",maxc,max);

  return 0;
}
