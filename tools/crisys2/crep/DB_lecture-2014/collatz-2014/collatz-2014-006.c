#include <stdio.h>

int main()
{
  int n, amari;
  amari = n % 2;
  printf("数字を入力してください：", n);
  scanf("%d", &n);
  for( n = 2; n <= 58   ; n++  ){
    if( amari == 0 )
      n = n%2;
    if( amari == 1)
      n = 3 * n + 1;
    if(n == 1)
      break;
  }


  
  for ( n = 0; n < 53 ; n++)
   printf("%d", n);


  return 0;
}
 
