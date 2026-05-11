#include <stdio.h>

int main(int argc, char *argv[])
{
  int i[5], j, sum = 0;

  if(argc != 2){
    printf("再入力してください\n");
    printf("入力方法は :<プログラム名> <アルファベット(〜5文字)>\n");
  } /* 引数のチェック */

  else{
    for(j = 0; j < 5; j++)
      i[j] = 0;
    for(j = 0; *(argv[1] + j) != '\0'; j++){
      i[j] = *(argv[1] + j) - 64;
      if((i[j] < 1)||(i[j] > 26)){
        printf("再入力してください\n");
        printf("入力方法は :<プログラム名>_<アルファベット(〜5文字)>\n");
        return 0; /* 入力がアルファベットでないなら終了 */
      }
    }
      for(j = 0; i[j] != 0; j++)
        sum = sum * 26 + i[j]; /* 26進数 -> 10進数 */
      printf("%s -> %d\n", argv[1], sum);
  }

  return 0;
}