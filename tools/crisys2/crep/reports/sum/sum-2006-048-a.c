#include <stdio.h>
#include <stdlib.h>

int sum1(int n);
int sum2(int n);

int sum1(int n){
  int i,sum;

  if(n > 0){   
    sum = 0;
    for(i = 1; i <= n; i++){
      sum += i;
    }
    return sum;
  }else{   
    return 0;
  }
}

main(){
  int n;
  char s[256];
  
  printf("Input a natural number:");
  n = atoi(fgets(s,256,stdin));
  
  printf("result by sum1: %d\n",sum1(n));
  printf("result by sum2: %d\n",sum2(n));
}

int sum2(int n){
  if(n > 0){ 
    return sum2(n-1) + n;
  }else{   
    return 0;
  }
}
