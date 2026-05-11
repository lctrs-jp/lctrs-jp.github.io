#include <stdio.h>

int main(void)
{
  int i, j = 0;


  printf("数値を入力してください");
  scanf("%d", i);

  for(;i != 1;){
    printf("%d-", i);
    if(i >= 2){
      if(i % 2 == 1)
	j = j + i * 3 + 1; 
      else
	j = j + i / 2;
    }
  }
  return ;


}
