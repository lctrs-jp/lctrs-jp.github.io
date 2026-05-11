#include<stdio.h>

int main(void){
  
  int k = 0;
  while(k < 2){
  printf("2以上の整数を入力してください:");
  scanf("%d",&k);
  }
  printf("%d",k);
  while(k != 1){
    if(k % 2 == 1){
      k = k * 3 + 1;
      printf( "- > %d",k);
    }
    else{
      k /= 2;
      printf("- > %d",k);
    }
  }
  return 0;
}
     
