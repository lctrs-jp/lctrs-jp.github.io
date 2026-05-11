//10月30日課題４
//入力された文字列の中に含まれる各数字の数を表示するプログラム
#include <stdio.h>
#include <string.h>

int main()
{
  char str[100];
  int i, j;
  int count;

  printf("数字列を入力してください（長さ100以下） :");
  fgets(str, 100, stdin);

  for (i = 48; i < 58; i++){
    count = 0;
    for (j = 0; j < strlen(str) - 1; j++){
      if (str[j] == i){
	count++;
      }
    }
    printf("%c は %d個含まれています．\n", i, count);
  }

  return 0;
}
