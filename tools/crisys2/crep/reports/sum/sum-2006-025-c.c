#include <stdio.h>

int sum2(int n);

int sum1(int n){
  int i,j;

  j=0;
  for(i=1;i<=n;i++){
    j=j+i;
  }
  return(j);
}

main(){
  int i;
  
  i=0;
  printf("Input a natural number: ");
  scanf("%d",&i);

  printf("result by sum1: %d\n",sum1(i));
  printf("result by sum2: %d\n",sum2(i));

}

int sum2(int n){
  if(n>0){
    return(sum2(n-1)+n);
  }else{
    return(0);
  }
}
