//文字列に含まれる各数字の数を表示するプログラム
//2014.10.30
//

#include <stdio.h>

int main()
{
  int i, n;
  char str[128];
  char m;

  printf("文字列を入力してください:");
  fgets(str, 128, stdin);

  for(m = '0'; m <= '9'; m++) {
    n = 0;
    for(i = 0; str[i] != '\0'; i++)
      if(str[i] == m)
        n++;

    printf("%c は %d 個含まれています\n", m, n);
  }

  return 0;
}
