#include <stdio.h>

int main(void)
{
  int number;

  printf("2以上の整数を入力してください\n");
  scanf("%d", &number);
  printf("%d", number);

  while(number != 1){
    if(number % 2 == 0){
      number = number / 2;
      printf("-> %d ", number);
    }
    else{
      number = number * 3 + 1;
      printf("-> %d ", number);
    }
  }
  return 0;
}
