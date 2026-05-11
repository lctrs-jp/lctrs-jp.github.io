#include <stdio.h>
#include <string.h>

int main(void)
{
  char a[101];//入力される文字列を保持する配列
  //cはそれぞれの数字の数を保持する配列
  int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int i, j, k;


  printf("数字列を入力してください(長さ100以下) : ");
  fgets(a, 101, stdin);
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 101; j++) {
      if (a[j] == (i + 48))//charで０なら１０進法では４８
	b[i]  = b[i] + 1;
    }
  }

  //結果を表示する
  for(k = 0; k < 10; k++)
    printf("%d は %d個含まれています\n", k, b[k]);

  return ;
}
	
