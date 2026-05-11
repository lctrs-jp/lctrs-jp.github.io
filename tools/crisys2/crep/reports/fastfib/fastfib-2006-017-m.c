#include <stdio.h>

int fastfib(int n){
  int i,a,b,buf;
  
  if(n<0){
    return (0);
  }else{
    a = b = 1;
    for(i = 3;i<=n;i++){
      buf = a + b;
      a = b;
      b = buf;
    }
    return b;
  }
}

main(){
  int n;
  printf("Input a natural number: ");
  scanf("%d",&n);

  if(fastfib(n) == 0){
    printf("Input a positive number (Fib(%d) = 0)\n",n);
  }else{
    printf("%d : %d\n",n,fastfib(n));
  }
}
