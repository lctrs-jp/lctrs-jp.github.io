#include<stdio.h>

int sum1(int n){
  int i,j=0;
  for(i=0;i<=n;i++){
    j=i+j;
   }
  return j;
}

main(){
  int no1,no2;

  printf("Input sum1\n");
  scanf("%d",&no1);

  printf("Input sum2\n");
  scanf("%d",&no2);

  printf("sum1=%d\nsum2=%d\n",sum1(no1),sum2(no2));

}

int sum2(int n){
  int i;
  if(n==0 || n<0){
    return 0;
  }else{ 
    return(n+sum2(n-1));
  }
}
