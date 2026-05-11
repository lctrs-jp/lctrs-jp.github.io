//以下の操作をnが1になるまで繰り返す過程を表示するプログラム
//(i)nが偶数なら n/2　(ii)nが奇数なら 3n+1
#include <stdio.h>

int main()
{
  int i;
  int n = 0;

  //nに数値を入力 
  while (1){
    printf("２以上の整数を入力してください: ");
    scanf("%d", &n);
    if (n > 0){
      break;
    }
  }

  //過程を表示しつつ計算
  printf("%d ", n);
  while (n != 1){
    //偶数ならn/2
    if (n % 2 == 0){
      n = n / 2;
    }else{//奇数なら3n+1
      n = 3 * n + 1;
    }
    printf("-> %d", n);
  }
  printf("\n");

  return 0;
}
