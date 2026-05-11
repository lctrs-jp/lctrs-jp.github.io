#include <stdio.h>
#include<string.h>

int main()
{
  int n = 0, i ,num = 0,max, cnt[26] = {} ;
  char  max2[26]={};
char str[101]={};

  printf("英字列を入力せよ(長さ100以下):");
  fgets(str , 101 ,stdin);

  n=strlen(str)-1;

  for(i=0;i<=n;i++)
    {
    if(str[i] >= 97 && str[i] <= 122){
      cnt[(int)str[i] - 97]++;
         }
    if(str[i] >= 65 && str[i] <= 90){
      cnt[(int)str[i] - 65]++;          }
    
  }
  max=0;
  int j;
  for(j=0;j<26;j++)
    {
     if(max<cnt[j]){
	max=cnt[j];}
      
    }
  int k;
  char o;
  for(k=0;k<26;k++){
    if(cnt[k]=max){
      o=max2[k];}
  }

  printf("最頻出文字は%c\n" ,o);
    printf("出現回数は%d回\n" , max);
  return 0;
}
