#include <stdio.h>

int main()
{
  char buf[101];/*100字まで扱うとするので、配列の長さは101*/
  int i ,j,k, cnt[26] , max;
  for( i = 0 ; i < 26 ; i++) cnt[i] = 0;
  /*整数i（26以下）の個数をcnt[i]に格納*/

  printf("文字列を入力してください(1000字以下):");
  fgets(buf, 101, stdin);

  for( i = 0 ; buf[i] != '\0' ; i++ ){
    if( 'a' <= buf[i] && buf[i] <= 'z')
      cnt[buf[i]-'a']++; /*文字を数値に変換*/
    else if('A'<=buf[i] && buf[i] <= 'Z')
      cnt[buf[i]-'A']++;/*文字を数値に変換*/
  }
  max = 0;
  for (j = 0; j < 25; j++){
    if (max<cnt[j])
      max = cnt[j];
    k=j;
  }
  printf("最多出現回数は　%c の　%d　回です。\n",'a'+k ,max);

    return 0;
}
