#include <stdio.h>
#include <string.h>

int main ()
{
  int i, j, k, count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char str[101];

  printf("数字列を入力してください（100文字以下）:");
  fgets(str, 101, stdin);

  printf("\n");

  k = strlen(str);

  for (i = 0; i <= 9; i++) {
    for (j = 0; j < k; j++) {
      if (str[j] == i +  48)
	count[i] = count[i] + 1;
    }
  }

  for (i = 0; i <= 9; i++) 
    printf("%dは%d個含まれています\n", i, count[i]);

  return 0;
}
