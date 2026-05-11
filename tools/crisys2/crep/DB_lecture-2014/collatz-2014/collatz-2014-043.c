#include <stdio.h>

int main(void)
{
  int n,
  printf("2以上の整数を入力してください: ");
  scanf("%d", &n);
  printf("%d", n);
  while(n = 1){
    if(n % 2 == 0){
      n = n / 2; 
      printf("-> %d", n);
}
    else{
      n = 3 * n + 1;
      printf("-> %d", n);
}
  }

  return 0;
}
