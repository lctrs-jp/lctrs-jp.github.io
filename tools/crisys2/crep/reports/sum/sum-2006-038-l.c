#include <stdio.h>

int sum1( int n)
{
  int i,j;
  if(n < 0 ){
    return(0);

  }else{
    for(i=0;i<=n;i++){  
    j = i + j; 
    }
  return (j);
  }
}

main ()
{
  int n;
  printf("Input a natural number ");
  scanf("%d",&n);
  printf("result by sum1: %d\n",sum1(n)); 
  printf("result by sum2: %d\n",sum2(n));

}

int sum2( int n )
{
  if(n < 0){
    
    return (0);
  }else if (n == 1){
    return(1);
  }else{
    
    return( sum2(n-1) + n);  
  }
}
