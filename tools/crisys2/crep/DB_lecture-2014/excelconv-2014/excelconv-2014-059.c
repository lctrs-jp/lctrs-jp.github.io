#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int i; //繰り返し変数
  int toint = 0;
  char Alf[50] = "";

  scanf("%s", Alf);
  for( i = 0; Alf[i] != '\0' ; i++){
    if('A' <= Alf[i] && Alf[i] >= 'Z')
      toint += ( Alf[i] - 64 ) * pow( 26, i + 1);
  }
  printf("%d", toint);

  return 0;
}