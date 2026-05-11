#include <stdio.h>

int main(void)
{
  int n;

  printf("2以上の整数を入力してください:");
  scanf("%d", &n);

  printf("%d", n);
  //nが1になるまで繰り返す
  while(n > 1){
    //偶奇の判定
      if((n % 2) == 0) {
	n /= 2; //nにn/2を代入
      printf(" -> %d", n);
    }
    else{
      n *= 3; //nにn*3を代入
      n++; //nにn+1を代入
      printf(" -> %d", n);
    }
  }
  printf("\n");

  return 0;
}
