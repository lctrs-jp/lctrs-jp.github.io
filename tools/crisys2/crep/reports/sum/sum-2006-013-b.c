#include <stdio.h>

int sum1( int n )
{
	int m,i;

	m = 0;
	if ( n < 0 ){		
		return 0;
	}else{
		for( i = 0; i <= n; i = i++){ 
			m = m + i;
		}
		return m;	
	}
}

int sum2( int n );

main()
{
	int num;

	printf( "Input a natural number  >" );
	scanf( "%d" , &num );	

	if( sum1(num) == 0 ){
		printf( "Input a natural number \n" ); 
	}else{
		printf( "result by sum1: %d \n", sum1(num) );
		printf( "result by sum2: %d \n", sum2(num) ); 
	}

	return 0;
}

int sum2( int p)
{
	if( p < 0 ){		
		return 0;
	}else{
		return ( p + sum2( p - 1 ) ); 
	}
}
