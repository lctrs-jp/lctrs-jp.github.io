#include <stdio.h>

int sum1( int n )
{
  int i, total1;
  total1 = 0;
  
  if( n < 0 ){
    return 0;
  }else{
    
    for( i = 0; i <= n ; i++ ){
      total1 = total1 + i;
    }

    return total1;
  }  
}

int sum2( int n );

main()
{
  int num;
  int result1, result2;
  
  printf( "Input a natural number: " );
  scanf( "%d", &num );
  
  result1 = sum1( num );
  result2 = sum2( num );
  
  if( (result1 == 0) || (result2 == 0) ){
    printf( "Input is not a natural number.\n" );
  }else{ 
    printf(" result by sum1: %d \n result by sum2: %d \n", result1, result2 );
  }

}

int sum2( int n )
{
  if( n < 1 ){
    return 0;
  }else{
    return ( n + sum2( n - 1 ) );
  } 
}
