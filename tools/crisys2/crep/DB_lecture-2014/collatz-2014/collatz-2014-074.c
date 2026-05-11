#include <stdio.h>

int main (void)
{
  long int i,num;

  printf("2以上の整数を入力してください：");
  scanf("%ld",&num);
  printf("%ld ",num);  
  while (num != 1){ //1になるまで計算する
    i = num % 2;
    if (i){           //奇数なら 
      num = (num * 3) + 1;
    }else{          //偶数なら
      num = num / 2;
    }
    printf("-> %ld ",num);
  }
  printf("\n");  
  return 0;
}
