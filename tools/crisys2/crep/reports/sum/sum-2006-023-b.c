#include<stdio.h>

int sum1(int n){
  
 int i,sum;
 
 sum=0;
 
 if(n < 0){
   return 0;
 }else{
 for(i=0;i<=n;i++){
   sum=sum+i;
}
 return(sum);
 }
}


main(){

  int num;
  
    printf("Input a natural number: ");
    scanf("%d",&num);
    
    if(num >= 65536){
      printf("overflow\n");
    }else{
    printf("result by sum1: %d\n",sum1(num));
    printf("result by sum2: %d\n",sum2(num));
}
}

int sum2(int n){
  if(n <= 0){
    return 0;
   }else{
   return(n + sum2(n-1));}
}
