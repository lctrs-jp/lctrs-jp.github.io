#include <stdio.h>

int fastfib(int n){
  int x=1,y=0,z,i;
    
  if(n <= 1){
    if(n < 0){
      n = 0;
    }
    return n;
  }else
    if(n >46){
      return -1;
    }else{
      for(i=1;i<n;i++){
	z = x;
	x = x + y;
	y = z;
      }
    }
  return x;
}

int main(){
  int n,ans;

  printf("Input a natural number: ");
  scanf("%d",&n);

  if(n<0){
    printf("Illeagal input.\n");
    return 0;
  }
  ans = fastfib(n);
  if(ans == -1){
    printf("Overflow.\n");
  }else{
    printf("%dth Fibonacci number: %d\n", n , ans);
  }
  return 0;
}
