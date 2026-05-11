#include <stdio.h>
#include <string.h>

int excel(char src[]);
int rui(int n,int i);

int main(int argc, char *argv[])
{
  if (argc != 1)
    printf("%d\n",excel(argv[1]));

  return 0;
}



int excel(char *src)  //文字列を数字に変換する関数
{   
  if (*src)                                                                //n桁目がnull文字でないなら
    return (*src - 64) * rui(26,strlen(src)-1) + excel(src +1);            //n桁目の数字 * 26の(n-1)乗 + n-1桁目の計算をしたもの(再起)　を返す
  
  else                                                                     //null文字なら0を返す
    return 0;
}



int rui(int n,int i)        //nのi乗を計算する関数
{
  int t = 1;  
  
  for (;i >= 1;i--)
    t = t * n;
  
  return t;
}
