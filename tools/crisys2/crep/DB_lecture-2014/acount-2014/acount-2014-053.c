#include <stdio.h>

int main()
{
  char moji[101], mode;
  char oldmode = '0';
  int i, j, count;
  int oldcount = 0;
  printf("文字列を入力してください(長さ100以下): ");
  scanf("%s", moji);

  /*文字の出現回数を数える*/
  for( i = 0; i < 101; i++){
    mode = moji[i];
    count = 1;
    for( j = i + 1; j < 101; j++)
      if( mode == moji[i])
      count++;

    /*最頻出かどうか比較する*/
    if(count > oldcount){
      oldmode = mode;
      oldcount = count;
    }
  }
  printf("最頻出文字は %s です\n", oldmode);
  printf("出現回数は　%d です\n", oldcount);
 
  return 0;
}
