#include <stdio.h>


int main ()
{
  int i, num;
  
  printf("2以上の整数を入力してください : ");
  scanf("%d", &num);
  printf("%d", num);

  while(num != 1)
    {
      if(num%2==0)
	{
	  num = num / 2;
	  printf(" -> %d", num);
	}
      else 
	{
	  num = (num * 3) + 1;
	  printf(" -> %d", num);
	}
      
    }
  
  
  return 0;
}
