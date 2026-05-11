#include <stdio.h>

int power(int a, int b);

int main(int argc, char *argv[])
{
  int i;
  int j = 0;
  int k = 0;
  int n = 0;

  if(argc == 2){
    for(i = 0; argv[1][i] != '\0'; i++) /* 改行文字削除 */
      if(argv[1][i] == '\n')
        argv[1][i] = '\0';

    for(i = 0; argv[1][i] != '\0'; i++) /* 文字数を得る */
      n++;

    for(i = 0; argv[1][i] != '\0'; i++){
      k = k + (argv[1][n - 1 - i] - 64) * power(26,j);
      j++;
    }

    printf("%d ", k);
  }

  return 0;
}


int power(a,b) /* 累乗計算の関数 */
{
  int p = 1, q;

  for(q = 1; q <= b; q++)
    p = p * a;

  return p;
}

