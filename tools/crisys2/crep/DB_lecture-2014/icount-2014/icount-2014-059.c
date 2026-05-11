#include <stdio.h>


int main()
{
  char text [100];
  int i, j, k;
 
  printf("数字列を入力してください。:");
  fgets( text, 40, stdin);

  for ( i = 0; i < 10; i++){
    k = 0; 
    for ( j = 0; text[j] != '\0'; j++){
      if ( i == text[j] - '0' )
	k++;
    }
    printf("%dは%d個含まれています。\n",i ,k);
  }

  return 0;
}
