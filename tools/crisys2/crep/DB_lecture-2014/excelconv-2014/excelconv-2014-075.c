#include <stdio.h>
void conv(char *argv);
int excelconv(char *argv, int n);

int main(int argc, char *argv[])
{
  int i, n = 0;
  /* 引数なし、または2より多い場合は処理しない */
  if (argc != 2)
    return 0;

  /* 入力された引数が5桁より多い場合も処理しない */
  while (*(argv[1] + i) != '\0') {
    i++;
  }
  if (i > 5)
    return 0;

  conv(argv[1]); // アルファベットを対応する数字に変換する

  printf("%d\n", excelconv(argv[1], n)); // 出力

  return 0;

}
/* アルファベットを数字に変換する関数 */
void conv(char *argv) {
  int i;
  for (i = 0; *(argv+i); i++)
    *(argv+i) = *(argv+i) - 'A' + 1;

  return;
}

/* 26進数を10進数に変換する再帰関数 */
int excelconv(char *argv, int n) {
  n = 26 * n + *argv;
  if (*(argv+1) != '\0')
    n = excelconv((argv+1), n);

  return n;

}