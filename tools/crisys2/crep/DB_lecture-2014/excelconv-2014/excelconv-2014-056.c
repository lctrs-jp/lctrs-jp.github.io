#include <stdio.h>
#include <math.h>
#include<string.h>
double excel(char trg[], int n);

int main(void)
{
  int i = 0;
  int j;
  int k = 0;
  char alp[6], copy[6];

  fgets(alp, 6, stdin);
  
  i = strlen(alp) - 1;

  strcpy(copy, alp);

  for(j = strlen(alp) - 2; j >= 0; j--){
	alp[k] = copy[j];
    k++;
  }

  printf("%f", excel(alp, i));

  return 0;
}

double excel(char trg[], int n)
{    
  if(n == 1)
    return trg[0] - 64;
  else 
    return (trg[n - 1] - 64) * pow(26.0, n - 1) + excel(trg, n - 1) ;
}

