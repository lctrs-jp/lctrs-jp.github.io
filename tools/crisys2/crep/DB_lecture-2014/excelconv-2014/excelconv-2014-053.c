#include <stdio.h>
#include <string.h>
#include <math.h>

int excelconv(char trg[]);

int main()
{
  int n;
  char str[6];


  scanf("%s", str );

  n = excelconv(str);

  printf("%d", n );

  return 0;
}


int excelconv(char trg[])
{
  int i,j,k,len;
  char src[6];

  len = strlen(trg);
  src[len] = '\0';

  for( k = 0; k < len; k++){ /* 文字列を逆にする */
    src[k] = trg[len-k-1];
  }

  j = 0;
  for( i = 0; src[i] != '\0'; i++){
    j = j +(src[i] - 'A' + 1) * pow( 26, i ); /* 26進数を10進数にする */
  }

  return j;
}
