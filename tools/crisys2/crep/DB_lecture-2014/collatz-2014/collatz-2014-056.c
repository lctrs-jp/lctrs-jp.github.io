#include <stdio.h>

int main()
{
  int num;
  printf("整数を入力してください: ");
  scanf("%d", &num);
  printf("%d →", num);

  /*入力された数を1にする*/
  while(num > 1){
    if(num % 2 == 0)
      num = num / 2;
    else if (num % 2 == 1)
      num = num * 3 + 1;

    /*過程を表示*/
    printf("%d →", num);
  
    if(num == 2)
      break;
  }
  printf("1\n");
 
  return 0;
}
