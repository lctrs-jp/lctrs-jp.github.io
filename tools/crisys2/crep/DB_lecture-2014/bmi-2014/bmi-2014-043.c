#include <stdio.h>

int main()
{
  int t ;
  float s ;
  scanf("%d , %f" , &t ,&s );
  printf("%d/(%f*%f) = %f\n", t , s , s , t/(s*s) );
  return 0;
} 
