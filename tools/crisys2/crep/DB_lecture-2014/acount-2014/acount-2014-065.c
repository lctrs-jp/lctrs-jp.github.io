#include <stdio.h>

int main()
{
  char buf[101]; //100桁までの文字列を扱う
  int i, max, cnt[26];
  for( i = 0 ; i < 26 ; i++)
    cnt[i] = 0; //アルファベット26文字の個数を格納

  printf("文字を入力してください(100文字以下) :");
  fgets(buf, 101, stdin);//文字列の入力

  for(i = 0 ; buf[i] != '\0' ; i++){
    if( 65 <=buf[i] && buf[i] <= 90)
      buf[i] = buf[i] + 32;//大文字を小文字に変換
  }
  for(i = 0 ; buf[i] != '\0' ; i++)
    if( 97 <= buf[i] && buf[i] <= 122 )
      cnt[buf[i] - 97] ++;
  
  for( i = 0 ; i < 26 ; i++ ){
     if(max < cnt[i])
	max = cnt[i];
  }
        printf("最頻出文字%c は%d 個含まれています.\n",buf[max], max );
    return 0;
}
