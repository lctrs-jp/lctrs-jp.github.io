#include <stdio.h>

int main(void)
{
  int inp, x;
  printf("2以上の整数を入力してください : ");
  scanf("%d", &inp);

  x = inp;
  printf("%d ", x);
  while(x != 1){
    if(x % 2 == 0){
      x = x / 2;
      printf("-> %d ", x);
    }
    else{
      x = (x * 3) + 1;
      printf("-> %d ", x);
    }
  }
  printf("\n");

  return 0;
}
