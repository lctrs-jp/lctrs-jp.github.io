#include <stdio.h>
#include <string.h>


int main(void)
{
  char inputs[101];
  int i;
  int counts[10];


  printf("数字列を入力してください(100以下): ");
  fgets(inputs, 101, stdin);


  /* countsの初期化 */
  for (i = 0; i < 10; i++) {
    counts[i] = 0;
  }


  /* 入力された数字のカウント */
  for (i = 0; i < strlen(inputs); i++) {
    if (inputs[i] >= 48 && inputs[i] <= 57)
      counts[inputs[i] - 48]++;
  }


  /* 結果の表示 */
  for (i =0; i < 10; i++) {
    printf("%d は %d個含まれています.\n", i, counts[i]);
  }


  return 0;
}
