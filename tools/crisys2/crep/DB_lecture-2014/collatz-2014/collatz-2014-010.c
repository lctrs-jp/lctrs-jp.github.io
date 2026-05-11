#include<stdio.h>

int main()
{
  int n;
  
  printf("2以上の整数を入力してください\n");
  scanf("%d", &n);
  

  while( n != 1){
    if(n % 2 == 1){
      n = 3 * n + 1;
    }
    else{
     n = n / 2;
    }
    
	printf("%d\n", n );
  }

  return 0;
}
