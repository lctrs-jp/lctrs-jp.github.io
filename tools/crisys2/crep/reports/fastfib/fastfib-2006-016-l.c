#include<stdio.h>

int fastfib(int num)
{
    int a=1, b=1, c=0, i;

    if(num==1) return 1;
    else if(num==2) return 1;
    else{
        for(i=0; i<num; i++){
	  c = a + b;
          a = b;
          b = c;
	}
	return c;
    }
}
    

int main(void)
{
    int num, fibnum;

    printf("Input a natural number: ");
    scanf("%d", &num);
    
    if(num<=0) printf("Input a natural number.\n");
    else{
      fibnum=fastfib(num);

      if(fibnum<0) printf("Overflow.\n");
      else
	printf("fib(%d) = %d\n", num, fibnum);
    }
    return 0;
}

