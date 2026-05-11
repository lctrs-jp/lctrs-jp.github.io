#include <stdio.h>

int change(char c[]);


int main(int num, char *ex[]){

  printf("%d\n", change(ex[1]) );

  return 0;
}

int change(char c[]){

  int i, j = 1;

  if( c[0] == '\0')
    return 0;
  else{
    for( i = 1; c[i] != '\0'; i++)
      j = j * 26;
    
    j = ( c[0] - 'A' + 1 ) * j;
    
    return  j + change( c + 1 );
  }
}
