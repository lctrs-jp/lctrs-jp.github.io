#include<stdio.h>
#include<string.h>

int main(int argc,char argv[])
{ 
  char *str = argv[1];
  int i,j,m;
  int n = 0;
  int count = 0;

  for( i = 0; i < strlen(str); i++){
    j = str[i] - 'A' + 1;
    m = 1;
    for(n = strlen(str) - i; n > 1; n--)
      m = m * 26;
    count = count + (m * j);
  }
  
  printf("%d\n", count);
  
  return 0;
}
  
