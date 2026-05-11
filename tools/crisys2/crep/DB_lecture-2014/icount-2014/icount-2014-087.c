//文字列が入力されたとき、その中に含まれる各数字の数をそれぞれ表示するプログラム
#include<stdio.h>

int main(void)
{
  char str[80];
  int i, m[9], n, k, l;

  for (n = 0; n < 10; n++){
    m[n] = 0;
  }

  printf("文字列を入力してください:");
  fgets(str, 80, stdin);
  for(i = 0; str[i] != '\0'; i++){
    if(str[i] == 48){
      m[0] = m[0] + 1;
    }
    for (k = 1; k < 10; k++)
      if(str[i] == k + 48){
	m[k] = m[k] + 1;
      }
  }
  for (l = 0; l < 10; l++){
    printf("%dは%d個含まれています。\n", l, m[l]);
  }
  return 0;
}
