#include <stdio.h>
#include <string.h>

int main(void)

{
  int a, i, t;
  char str[101];
  printf("数字列を入力して下さい(長さ100以下):");
    scanf("%s", str );
   
  for(i = 0; i < 10; i++)
    { 
      t = 0;
      
      for(a = 0; a < strlen(str) ; a++)
	if(str[a] == i + 48) 
	  t = t + 1;

      printf("%d は %d個含まれています。\n", i, t);
    }
  return 0;
}

