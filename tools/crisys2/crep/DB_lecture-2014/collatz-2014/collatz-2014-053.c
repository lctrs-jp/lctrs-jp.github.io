#include <stdio.h>

int main ()
{
  int n; 

  printf ("数字を入力してください");
  scanf ("%d", &n);


  while (n>1){
     if (n%2 == 0)
        n = n/2;
     if (n%2 == 1)
        n = n*3 +1;
  }   
     printf ("_> %d", n);
  

  return 0;
}

