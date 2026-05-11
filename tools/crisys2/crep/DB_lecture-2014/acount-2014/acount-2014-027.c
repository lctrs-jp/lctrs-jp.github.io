#include<stdio.h>
#include<string.h>
int main()
{
  int i,t,max,x[26];
  char a[100];
  printf("文字列を入力してください\n");
  fgets(a,100,stdin);
  for(i=0;i<=25;i++)
    x[i]=0;
  
  for(t=0;t<strlen(a);t++){
    for(i=0;i<=25;i++){
      if(a[t]=='A'+i || a[t]=='a'+i){
      x[i]++;
  break;
    }
    }
  }
  max = 0;
  for(i = 0;i <= 25;i++){
    if(max < x[i])
      max = x[i];
  }
  for(i= 0;i <= 25;i++){
    if(x[i]==max){
      printf("最頻出文字は %c で %d 個です\n",'a'+i,max);
    }
  }
}
    
  
