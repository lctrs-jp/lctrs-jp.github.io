#include <stdio.h>

int fastfib(int num);

main(){

  int num;
  printf("Input non-negative integer: ");
  scanf("%d",&num);
  if(num<0){
    printf("Error");
    return 0;
  }

  printf("fastfib(%d)=%d\n",num,fastfib(num));

}

int fastfib(int num){
  int f0,f1,f2;

  for(f0=f1=1;num>=2;num--){
    f2=f1+f0;
    f0=f1;
    f1=f2;
  }

  return f1;

}
