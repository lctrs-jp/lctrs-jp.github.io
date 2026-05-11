#include <stdio.h>

int main()
{
  int n;

  printf("数字を入力してください: ");
  scanf("%d", &n);

  while (1)
    {
      printf("%d",n);

      if (n%2 == 1)    /*奇数の場合*/
	n = (n * 3) +1;
      else             /*偶数の場合*/
	n = n / 2;

      printf("->");

      if (n == 1){     /*１になったら、１を表示してループを抜ける*/
	printf("%d",n);
	break;
      }

    }

  printf("\n");
  return 0;
}
