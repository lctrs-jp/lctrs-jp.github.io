#include <stdio.h>
#include <string.h>

int main()
{
  int n;

  printf("整数を入力してください: ");
  scanf("%d", &n);
  while(n != 1){
    if ( n % 2 == 0){
      n = n / 2;
      printf("%d\n",n );
   }
    else if(n % 2 == 1){
      n = (n * 3) + 1;
      printf("%d\n", n);
    }
  }

 return 0;
}
