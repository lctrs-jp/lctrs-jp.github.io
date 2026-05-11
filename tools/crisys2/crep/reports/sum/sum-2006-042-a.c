#include <stdio.h>

int sum1(int n){
	int i, s1;
	i = 0;
	s1 = 0;
	if(n <= 0){
		return(0);
		}else{
			for(i=1; i <= n; i++){
				s1 = s1 + i;
			}
			return s1;
		}
}

main(){
	int n, s2;
	printf( " input natural number : \n " );
	scanf( "%d" , &n);
	if(sum1(n) == 0){
		printf( " input nutural number\n " );
		}else{
			printf( " answer by sum1 : %d\n " , sum1(n));
			printf( " answer by sum2 : %d\n " , sum2(n));
		}
}

int sum2(int n){
	int i, s2;
	if( n <= 0){
		return(0);
	}else{
		return(sum2(n-1) + n);
	}
}
