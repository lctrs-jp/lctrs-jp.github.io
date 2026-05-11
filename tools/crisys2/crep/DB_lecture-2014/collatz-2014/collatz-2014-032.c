#include<stdio.h>

int main()
{
  int n;

  //文字の読み込み
  printf("１にしたい整数を入力してください(2以上 3*2^53以下) ");
  scanf("%d" , &n);
  
  do{  //ここで行為を繰り返す

    if(n % 2 == 0)
      n =n / 2;
    else
      n = (n * 3) + 1;

    printf("_> %d " , n);    //経過を表示する

  }while(n != 1);


  printf("\n");

  return 0;
}

