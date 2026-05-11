#include<stdio.h>

int main(void){

  int num;
  int i, j, k;
  
  printf("2以上の整数を入力してください:");
  scanf("%d", &num);
  
  printf("%d",num);
  
  //  while( num == 1){
  for( i = 0; i < 256; i++){    
    if(num == 1){
      break;   
    }    
    else if((num % 2) == 0)
      num = num / 2;
    else if((num % 2) == 1)
      num = 3 * num + 1;
    printf(" ->%d",num) ;
  }
  printf("\n");

  return 0;
}
