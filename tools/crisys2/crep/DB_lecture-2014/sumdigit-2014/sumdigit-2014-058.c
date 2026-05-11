#include<stdio.h>
int figcul(long n);
int sum_digit(long n);

int main(void){
  long num;
  
  printf("数字を入力\n");
  scanf("%ld",&num);
  printf("求まる値は%dです。\n",sum_digit(num));
  return 0;
}
int figcul(long n){
  int a = 0;
  while(n){
    n /= 10;
    a++;
  }
  

  return a;
}
      
int sum_digit(long n){
  
  int num[figcul(n)];
  int i;
  int sum = 0;
  int fig = figcul(n);

  for(i = 0;i < fig;i++){
    
    num[i]  = n % 10; 
    n = n / 10;
    sum += num[i];
    
  }
  printf("%d\n",sum);
  if(sum < 10)
    return sum;
  return sum_digit(sum);
} 
