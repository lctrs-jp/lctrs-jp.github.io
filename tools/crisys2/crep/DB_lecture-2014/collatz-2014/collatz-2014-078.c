#include <stdio.h>
#include <math.h>

int ans(int n);
int main(void)
{
  int i;
  int test[][2]={
    {10,1},
    {-999,0}
};

  i =0;
  while(test[i][0] != -999){
    if (ans(test[i][0])==test[i][1])
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %d\n",ans(test[i][0]));
      printf("  期待される結果  : %d\n",test[i][1]);
    }

    i++;
  }
  return 0;
}



int ans(int n)
{             ;
  while(n>=2){
    if(n%2==0)
      n=n/2;
    else
      n=n*3+1;}
}
