#include <stdio.h>

int main ()
{
  int i,j,k,l;
  char str[100];
  
  printf ("数字列を入力してください: ");
  fgets (str, 100, stdin);

  for (i = 0 ; i < 10 ; i++) {
    l = 0;
    k = i + 48;
     for ( j = 0 ; str[j]!= '\0' ; j++){
        if (str[j] == k ) {
	  l  = l + 1;
        }
      }
    printf("%dは%d個含まれている\n" ,i ,l);
  }

  return 0;
}

         
