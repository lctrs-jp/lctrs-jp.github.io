#include <stdio.h>

int fastfib(int n){
  int a,b,c,d;
  a=0;
  b=1;
  if(n<0){
    return(0);  
  }else if(n==1){
    return(1);  
  }else{
    for(c=2;c<=n;c++){
      d=a+b;  
      a=b;
      b=d;
    }
    return(d);
  }
}

main(){
  int n;
  printf("Input a natural number: \n");
  scanf("%d",&n);
  if(n>=0){
    printf("Fib(%d) = %d\n",n,fastfib(n));  
  }else{
    printf("Input a positive number. (Fib(%d) = %d)\n",n,fastfib(n)); 
  }
}
