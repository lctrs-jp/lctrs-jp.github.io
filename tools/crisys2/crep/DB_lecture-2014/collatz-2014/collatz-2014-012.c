#include<stdio.h>
int main(void)
{
  int num;
  printf("2以上の数字を入力してください:\n");
  scanf("%d", &num);
  printf("%d", num);

  while(num!=1){
    if(num%2==0)
      num = num/2;
    else
      num = num*3 + 1;
    printf("->%d",num); 
 }
  return 0;
}
