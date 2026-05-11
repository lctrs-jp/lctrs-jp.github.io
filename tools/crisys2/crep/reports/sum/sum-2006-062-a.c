#include<stdio.h>

int sum1(int n);
int sum2(int n);

int main()
{
        int n;
	printf("Input a natural number: ");
	scanf("%d", &n);
        printf("result by sum1: %d\n",sum1(n));
        printf("result by sum2: %d\n",sum2(n));
	return 0;
}

int sum1(int n)
{
 int a, b;
	
        if(n <= 0){
		return 0;              
        }else{
       	        for(a=1; a<=n; a++){   
      		b = b + a; 
		}
		return b;              
	}
}

int sum2(int n)
{
	if(n <= 0){                    
	return 0;
  }else if(n == 1){
	return 1;
  }else{
	return( n + sum2(n-1));
  }
}
