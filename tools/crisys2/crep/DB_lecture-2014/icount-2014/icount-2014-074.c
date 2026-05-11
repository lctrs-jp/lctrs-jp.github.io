#include <stdio.h>
#include <string.h>

int main (void)
{
  int i,t;
  char num[101];
  int count[10]={0,0,0,0,0,0,0,0,0,0};            //countには数字の個数をいれる

  printf("\n数字列を入力してください。（長さ100以下）：");
  scanf("%s",num);

  for (i = 0; i < strlen(num); i++){     //一文字ずつチェックしていく
    for (t = 0; t <= 9; t++){
      if (t+48 == num[i])          //文字列としての数字は内部的には+48した値となっている　例　"2" = 50
	count[t]++;                 //0～9の数字があればそれぞれのカウントを加算する
    }
  }
  
  for (i = 0; i <=9; i++){                  //0～9までの個数を表示
    printf("%d は %d 個含まれています。\n", i, count[i]);
  }

  return 0;
}
