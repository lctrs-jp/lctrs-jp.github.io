#include<stdio.h>

void main(void)

{
  char ad[200];
  int i, n;
  i = 0;
  n = 0;
  printf("\n 英字: "); 
  fgets(ad, 200, stdin);
 while (1)

    {
      if(ad[i] - 64 >= 1 && ad[i] - 64 <= 25 )
	n = n + 1;
      i = i+ 1;
      if(ad[0] == '\0' )
	break;

      n = n*26;
 }

 printf("\n = %d", n);
}
