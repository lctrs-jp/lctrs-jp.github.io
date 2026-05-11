#include<stdio.h>
int sum2(int num);
int sum1(int num){
	int sum,i;
	sum=0;
        if(num<0) return(0);
	else {
	
	for(i=1;i<=num;i++){
		sum=sum+i;
			}
}
	return sum;
}


main(){
	int num;
	printf("Input a natural number: ");
	scanf("%d",&num);
	printf("result by sum1: %d\n",sum1(num));	
	printf("result by sum2: %d\n",sum2(num));
	return 0;
}


int sum2(int num){
	if(num<0) return (0);
	else return (num+sum2(num-1));
}

