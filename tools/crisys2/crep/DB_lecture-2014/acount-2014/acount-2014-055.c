#include <stdio.h>
//入力した文字列内の最頻出文字の登場回数を表示
int main(void)
{
  int i,j,t,max;
  int count[26], ab[26];
  for(i=0;i<26;i++){
    count[i]=0;
    ab[i]=0;
  }
  char str[100];

  //文字列を入力
  printf("文字列を入力して下さい(長さ100以下):");
  fgets(str,101,stdin);
  
  //文字列内のアルファベットをカウントしていく
  for(i=0; str[i]!='\0'; i++){
    for(j=0; j<=25; j++){
      if(str[i]==j+65 || str[i]==j+97)
	count[j]++;
    }
  }

  //カウントした結果をソート用に別の配列へコピー
  for(i=0;i<=25;i++)
    ab[i]=count[i];

  //コピーした配列をソートし最頻出回数を調べる
  for(i=25; i<1; i--){
    for(j=0; j<i; j++){
      if(ab[j] < ab[j+1]){
	t = ab[j+1];
	ab[j+1] = ab[j];
	ab[j] = t;
      }
    }
  }
  max = ab[0];
  
  //結果を出力
  for(i=0; i<=25; i++){
    if(count[i] == max)
      printf("最頻出文字は%s%sの%d回です。\n", i+65, i+97, max);
  }
  return;
}



