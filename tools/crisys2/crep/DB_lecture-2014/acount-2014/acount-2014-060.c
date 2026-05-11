#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void)
{
  int i, k, t, n, x, y;
  x = 0;
  y = 0;
  char str[100];

  printf("文字列を入力してください: ");
  fgets(str,100,stdin);
  k = strlen(str);

  for(t = 0;t < 27;t++){ /* a(=97)からz(=122)の26文字をさがす */
    n = 0;
    for(i = 0;i < k;i++){ /* 一文字目から最後の文の中からtをさがす */
      if(str[i] == t + 97) /* 小文字 */
	n = n + 1; /* tの数を数える */
      if(str[i] == t + 65) /* 大文字 */
	n = n + 1;
      if(n >= x){ /* 最大数の文字とその数を保存 */
	x = n;
	y = t + 97;
      }
    }
  }
    printf("最頻出の文字は %d で %d 回出現します!\n", y, x);
    return 0;
}
