#include<stdio.h>
#include<string.h>

void downcase(char str[]); // 大文字を小文字に変換する関数

int main(void)
{
  char str[100];
  int count[10];
  int num,i,j;

  for(i=0;i<10;i++){
    count[i]=0;
  }

  printf("文字を入力してください:");
  gets(str);
  for(i=0;str[i]!='\0';i++){
    downcase(str[i])};
  for(i=0;str[i];i++){
  for(j=48;j<=57;j++){
     if(str[i]==j){
        count[j-48]+=1;
	return; 
     }
    }
  }

  for(num=0;num<=9;num++){
    printf("%dは%d個含まれています\n",num,count[num]);

  return 0;

}
/* 以下の関数を変更する */
void downcase(char str[]){
  int t;
  for(t=0;t<40;t++)
    if(str[t]<=90 & str[t]>=65)
      str[t]= str[t]+32;
    else
      str[t]=str[t];
  // 文字列中の大文字を小文字に変換する関数
  // ただし，変換するのは A から Z までのアルファベットだけで
  // それ以外の文字・記号は変更しない

  return;
}
