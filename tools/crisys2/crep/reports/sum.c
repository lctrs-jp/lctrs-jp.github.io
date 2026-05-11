#include <stdio.h>

int sum2(int n);

int sum1(int n)
{
  int i;
  int wa;

  wa = 0;
  for( i = 0 ; i <= n ; i++ ){
    wa += i;
  }

  return( wa );
}

int sum2( int n )
{
  int wa;

  if( n <= 0 ){
    wa = 0;
  }else{
    wa = n + sum2( n-1 );
  }

  return( wa );
}
