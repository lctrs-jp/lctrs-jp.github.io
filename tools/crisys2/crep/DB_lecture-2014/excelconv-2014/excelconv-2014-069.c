#include <stdio.h>
#include <string.h>

int stcnt(char *str)
{
  int s[4], t[4];
  int n, j, k, l, m, o, cnt;
  cnt = 0;
  /* t[0]からt[4]の初期値を0にする */
  for(n = 0; n < 5; n++)
    t[n] = 0;
  m = strlen(str);
  for(k = 0 ;str[k] != '\0'; k++)
    s[k] = str[k] - 64;
  /* s[] の数に26を(桁数-1)回かけるt[]を作る */
  for(l = 0; m > 0; l++, m--)
    t[l] = involve(s[l], m - 1);
  /* 文字が5桁未満の時にt[4]が1文字目の数字になる現象が起きたので、修正する */
    if(strlen(str) != 5)
      t[4] = 0;
    /* tの数をすべて足す */
    for(o = 0; o < 5; o++)
      cnt = cnt + t[o];
  return cnt;
}

/* 初期値aにb回26をかける関数 */
int involve(int a, int b)
{
  int ans;
  ans = a;
  while(b > 0){
    ans = ans * 26;
    b--;
  }
  return ans;
}

int main(int argc, char *argv[])
{
  printf("数値は%dです。",stcnt(argv[1]));
  return 0;
}

