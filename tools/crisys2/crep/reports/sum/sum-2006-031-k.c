#include<stdio.h>

int sum1( int n ){
  int count,i=0;

  if( n==0 ) return 0;
  else{
    
    for( count=1 ; count<=n ; count++ ){
      i = i + count;
    }
    return i;
  }
}

int sum2( int n );

main(){
  int num;
  
  printf("Input a natural number: ");
  scanf("%d",&num);
  
  printf("result by sum1: %d\n",sum1(num));
  printf("result by sum2: %d\n",sum2(num));

}

int sum2( int n ){
  if( n<=0 ) return 0;
  else{
    return (n + sum2( n-1 ));
  }
}
