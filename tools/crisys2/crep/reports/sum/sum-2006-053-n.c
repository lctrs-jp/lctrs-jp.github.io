#include <stdio.h>

int sum1( int n ){
	int m=0;
	if(n<=0){
		return(0);  
	}else{
		while(n>0){
			m=m+n;
			n--;
		}
		return(m);
	}
}

int sum2( int n );   

main(){
	int n;
	printf("Input a natural number.\n");
	scanf("%d",&n);
	if(n<0){
		printf("Input a positive natural number.\n");
	}else{
		printf("Summation from 0 to %d by sum1 is %d.\n",n,sum1(n));
		printf("Summation from 0 to %d by sum2 is %d.\n",n,sum2(n));
	}
}

int sum2( int n ){
	if(n<=0){
		return(0);   
	}else{
		return(n+sum2(n-1));    
	}
}
