#include<stdio.h>

int main()
{
  int n,m;
 
  printf("2以上の任意の整数を入力してください。:");
  scanf("%d",n);

  while(n = 1)
 {    
   if(n % 2 == 0) /*nが偶数の場合*/
    {
      n = n / 2;
      printf("%d\n",n);
    }
   else /*nが奇数の場合*/
    {
      n = n * 3 + 1;
      printf("%d\n",n);
    }

  printf("%d\n",n);
 }

  return 0;
}


