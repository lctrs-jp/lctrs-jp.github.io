#include <stdio.h>

void reverse(char trg[], char src[]);

int main (void)
{
  char trg[256];
  char src[256];
  int i;

  printf ("Input a string: ") ;
  scanf ("%s", trg);

  for (i = 0; i < 256; i++) {
    if (trg[i] == '\0')
      break;
  }
  
  while (i > 0) {
    i--;
    putchar(trg[i]);
    //src[i] == trg[i];  
    
  }
  //for(i = 0; i < 256; i++){
  //if(src[i] == '\0')
  //  break;
  //else
  //  putchar(src[i]);
  //} 
printf ("\n");

  return 0;
}
