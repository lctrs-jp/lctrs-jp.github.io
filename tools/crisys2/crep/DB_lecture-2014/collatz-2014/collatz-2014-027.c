#include<stdio.h>

int main()
{
  int n;

  printf(" n = ");
  scanf("%d", &n);

  for( n > 0 ; ;){
    if( n == 1)
      break;
    else{
      if( n % 2 == 1){
        n = 3 * n + 1;
        printf("%d\n", n );
      }
      else{
        n = n / 2;
        printf("%d\n", n );
      };
	    };
  }
  printf("%d", n);

  return 0;
}