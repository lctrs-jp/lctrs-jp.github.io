#include<stdio.h>

int main(void)
{
  int t;

  printf("好きな２以上の自然数を入力して下さい:");
  scanf("%d",&t);

  while(t>1){
    if(t % 2 == 0)
      t=t/2;
    else
      t=3 * t + 1;

    printf("%d\n",t);
  }

  if(t==1)
    printf("1");

  return 0;

}

