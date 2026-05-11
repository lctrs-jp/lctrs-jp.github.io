#include<stdio.h>

int sum1( int n );
int sum2( int n );

int main(void)
{
  int n;
  printf("Input a natural number: ");
  scanf("%d",&n);
  printf("result by sum1 is %d \n",  sum1(n) );
  printf("result by sum2 is %d \n",  sum2(n) ); 

  return 0;
}

int sum1( int n )
{
  int i;
  int a=0;

  if( n<0 ){
    return 0;
  }

  for(i=0;i<=n;i++){
    a  =  a + i;
  }    

  return a;
}

int sum2( int n )
{
  if( (n==0) || (n<0) ){
    return 0;
  }else if(n==1){
    return 1;
  }else{
    return ( n + sum2( n-1 ) );
  }
}
