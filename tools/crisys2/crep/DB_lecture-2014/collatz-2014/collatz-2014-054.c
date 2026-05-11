//2014.11.6
//********* ** **

#include <stdio.h>
#include <math.h>
int main()
{
  int num;

  printf("２以上の整数を入力してください:");
  scanf("%d", &num);

  while(num < 2 || 3 * pow(2, 53) < num) {
    printf("2から3×2^53までの整数を入力してください:");
    scanf("%d", &num);
  }

  printf("%d", num);

  while(num != 1) {
    if(num % 2 == 0) {
      num = num / 2;
      printf("-> %d", num);
    }

    else {
      num = 3 * num + 1;
      printf("-> %d", num);
    }
  }

  return 0;
}
