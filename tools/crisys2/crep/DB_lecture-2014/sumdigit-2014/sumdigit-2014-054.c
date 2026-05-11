# include <stdio.h>
int sum_digit(int n)

;int main(void)
{
  int a;

  printf("整数を入力してください\n");
  scanf("%d", &a);

  printf("%d", sum_digit(a));

  return 0;
}

int sum_digit(int n)
{
  int i = 0;

  while(n >= 10){
    while(n >= 1){
	  i = i + (n % 10);
	  n = n / 10;
	}
	n = i;
	i = 0;
  }

  return n;
}
	  
	  

 
