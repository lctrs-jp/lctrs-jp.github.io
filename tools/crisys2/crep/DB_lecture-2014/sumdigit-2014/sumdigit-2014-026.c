#include<stdio.h>
int sum_digit(int n);

int main(void)
{
  int i;
  
  int test[][2]
={
    {9,9},{10,1},{0,0},{55,1},{123,6},{128,2},{255,3},{123456789,9},
    {888888888,9},{2147483647,1},{-999,0}
  };

  i=0;
  while(test[i][0]!=-999){
    if(sum_digit(test[i][0])==test[i][1])
      printf("テスト%dは成功\n",i+1);
    else{
      printf("テスト%dは失敗!!\n",i+1);
      printf("作った関数の出力: %d\n",sum_digit(test[i][0]));
      printf("期待される結果 :%d\n",test[i][1]);
    }
    i++;
  }
  return 0;
}


int sum_digit(int n)
{
  int a=0,b=0,c=0;
  while(n>0){
    a=a+(n%10);
    n=n/10;
  }
    while(a>0){
      b=b+(a%10);
      a=a/10;
}
    while(b>0){
      c=c+(b%10);
      b=b/10;
    }

    return c;


}
