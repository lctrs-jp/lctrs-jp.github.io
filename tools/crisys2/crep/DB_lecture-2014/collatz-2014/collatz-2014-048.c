#include <stdio.h>

int main(void)
{
  int i;
  printf("２以上の数字を入力してください:");
  scanf("%d", &i );
  while(i != 1){
    if(i = 1)
      break;
    if( i%2 == 0 ){
      printf("%d", i/2 );
      i = i/2;
    }
    else{
      printf("%d",3*i + 1);
      i = 3*i+1;
      }
  }
  return 0;
}
