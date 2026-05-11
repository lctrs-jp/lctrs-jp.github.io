#include <stdio.h>


int main()
{
  int n;

  printf("数字を入力してください。\n");
  scanf("%d", &n );
  printf("\n");
  printf("%d ->", n );
 
  while( n > 2 )
    if ( n % 2 ){
      n = ( 3 * n ) + 1;
      printf("%d ->", n );
    }else{
      n = n / 2;
      printf("%d ->", n );
    }

  printf("1\n");
  
  return 0;
}
