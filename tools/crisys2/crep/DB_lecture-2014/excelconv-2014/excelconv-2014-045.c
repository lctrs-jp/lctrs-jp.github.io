#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  printf("%d\n", argc); /* 引数の数を確認 */
  int l, i, t;
  t = (argv[1][0] - 64); /* 最大桁の数字 */
  l = strlen(argv[1]);
  for(i = 1;i < l;i++)
    t = t*26 + (argv[1][i] - 64); /* 次に大きい桁数までを計算 */
  printf("%d\n", t);
  return 0;
}
  
  
