#include<stdio.h>

int main() {

  int num, i;
 
  printf("2以上の整数を入力してください。");
  scanf ("%d", &num);

  while(num > 1) {
  
  if((num % 2) == 1 & num !=1) {
     num = num * 3 + 1; }
  else if((num % 2) == 0) {
    num = num / 2; }
  
  printf("%d\n", num);
  
  }
  return 0;
  }
  
