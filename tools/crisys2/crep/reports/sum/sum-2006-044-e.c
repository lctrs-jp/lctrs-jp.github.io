#include <stdio.h>

int sum1(int n){
  int ans=0;
  if(n<0){
    printf("Input is illeagal.\n");
    return 0;
  }else{
    for(;n>=0;n--){
      ans = ans + n;
    }
    return ans;
  }
}

int sum2(int n);

main(){
  int n;

  printf("Summation from 1 to a given number will be calculated.\n number is: ");
  scanf("%d",&n);
  printf("sum1:%d\nsum2:%d\n",sum1(n),sum2(n));
}


int ans=0;
int sum2(int n){
  if(n<0){
    printf("Input is illeagal.\n");
    return 0;
  }else{
    ans = n + sum2(n-1);
    return ans;
  }
}
