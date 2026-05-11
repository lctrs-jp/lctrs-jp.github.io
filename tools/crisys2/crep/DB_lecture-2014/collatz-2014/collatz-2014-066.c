#include <stdio.h>

int main()
{
  int n;

  printf("数を入力してください(2以上3×2^53以下) ");
  scanf("%d", &n);

  while( n != 1){
      if( n %2== 0)
	n = n / 2;
      else
	n = n * 3 + 1;
      printf("%d",n);
      printf("\n");
    }
    return 0;
}
