#include <stdio.h>

int main() {
  int n;
  printf("数値を入力せよ : ");
  scanf("%d",&n);

  while(n!=1){
    printf("%d → ",n);
    if (n%2==0) {
      //偶数のとき2で割る
      n/=2;
    } else {
      //奇数の時3倍して1を加える
      n=3*n+1;
    }
  }
  printf("%d\n",n);

  return 0;
}
