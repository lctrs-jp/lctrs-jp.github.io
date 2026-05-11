#include<stdio.h>
#include<string.h>

int main()
{
  int x,y,u,z,count[26],max;
  char str[100],w;
  count[26]=0;

  printf("文字列を入力してください（長さ100以下）");
  scanf("%s",str);
  
  for(x=0;str[x]!='\0';x++){
    if(str[x]>=65&&str[x]<=90)
      str[x]=str[x]+32;
  }

  for(u=0;u<strlen(str);u++){
    if(str[u]=x){
      count[x]++;
	}  
  }   

  for(x=97;x<122;x++){
    if(max<count[x])
      max=count[x];
  }

  printf("最頻出文字は%cです",str[max]);

    printf("出現回数は%d回\n",max);

  return 0;

}
