#include <stdio.h>

void flowout(int n); //例の演算を繰り返し表示する。

int main(void)
{
  int a;

  printf("数字を入力してください。(2以上3＊2＾52以下）");
  scanf("%d",&a);

  printf("その数字で、偶数なら割る２、奇数なら三倍して足す１を繰り返します。");
  flowout(a);

  printf("完了しました。");

  return 0;
}

void flowout(int n)
{
  while(n!=1)
    {
      printf("%d -> ",n);
      if(n%2==0)
	n=n/2;
      else n=n*3+1;
    }

  printf("1");
}
