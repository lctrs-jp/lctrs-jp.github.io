#include <stdio.h>
int main() 
{
  int n;
  printf("2以上3*2^53以下の数字を入力してください");
  scanf("%d", &n);
  while(n!=1){
    if(n%2==0)
      printf("%d \n" ,n=n/2);    
   else
     printf("%d \n", n=3*n+1);
	} 
 
  return 0;
}
