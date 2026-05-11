#include<stdio.h>

int sum_digit(int n);

int main() {

  int n;

  printf("文字列を入力してください:");
  scanf("%d", &n);
 
  while(n > 9){
    n = n / 10 + (n % 10);
  }
  
  printf("値は%d", n);
  printf("\n");
 
  return 0;
}
