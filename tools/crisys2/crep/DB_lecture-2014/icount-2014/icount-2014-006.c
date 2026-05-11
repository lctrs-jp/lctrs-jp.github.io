#include <stdio.h>
//入力した文字列内の各数字の数をカウント
int main(void)
{
  int i,j;
  int num[10];
  for(i=0;i<10;i++)
    num[i]=0;
  char str[100];

  //文字列を入力
  printf("文字列を入力して下さい(長さ100以下):");
  fgets(str,100,stdin);
  
  //文字列内の数字をカウントしていく
  for(i=0; str[i]!='\0'; i++){
    for(j=0; j<10; j++){
      if(str[i]==j+48)/*文字コード４８番目が０*/
	num[j]++;
    }
  }

  //結果を出力
  for(i=0; i<10; i++)
    printf("%dは%d個含まれています。\n",i, num[i]);

  return;
}


