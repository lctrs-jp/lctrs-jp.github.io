#include <stdio.h>

int main(void)
{
  int i,a;
  printf("２以上の整数を入力してください: ");
  scanf("%d",&a );
  printf("%d ", a); 
  for(; a >= 2 ; ){
    if(a%2 == 0){
      a = a / 2;
    }
    else{
      a = a * 3;
      a = a + 1;
    }
    printf("-> %d ", a);
  }
  return 0;
}
      
