#include<string.h>
#include<stdio.h>

int main()
{
  char src[100];
  int i,j,k;
  int count;

  printf("100桁以下の数字を入力してください\n");
  gets(src);

  for( j = 0; j < 10; j++){
    count = 0;
    k = j + 48;
    for( i = 0; src[i] != '\0'; i++){
      if( src[i] == k)
	count = count + 1;
    }
    printf("%dは%d個含まれています\n", j, count);
  }
  return 0;
}
