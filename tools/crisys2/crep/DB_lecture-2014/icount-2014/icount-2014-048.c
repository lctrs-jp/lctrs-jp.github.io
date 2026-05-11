#include<stdio.h>
#include<string.h>

int main(void)
{
  int i, j, k, t;
  char num[101];
  
  printf("数字列を入力してください!\n");
  fgets(num,101,stdin);
  t = strlen(num);

  for(k = 0;k < 10;k++){ /* 0から9のどの数を数えるか */
    j = 0; /* その数の個数をカウント */

  for(i = 0;i < t;i++){ /* 文字列を先頭から順にみる */
    if((int)num[i] == k + 48) /* 数字は+48で数字として認識 */
      j = j+1;
  }
  printf("%d は %d 個あります!\n", k, j);

  }
  return 0;
}
