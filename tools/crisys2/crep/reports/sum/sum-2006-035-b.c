#include<stdio.h>

int sum1(int n ){
	int i,j;
	if(n<0){
		return 0;
	}
	else{
		j=0;
		for(i=0;i<=n;i++){
			j=j+i;
		}
		return j;
	}
}

main(){
	int n;
	printf("Input a natural number: ");
	scanf("%d",&n);
	printf("result by sum1: %d\n",sum1(n));
	printf("result by sum2: %d\n",sum2(n));
}

int sum2(int n ){
	 if(n<0){
		 return 0;
	 }
	 else{
		 if(n==0){
			 return 0;
		 }
		 else{
			 return(n+sum2(n-1));
		 }
	 }
 }
