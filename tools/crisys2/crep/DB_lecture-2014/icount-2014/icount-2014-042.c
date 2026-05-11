#include <stdio.h>

int main()
{
  char a[100];
  int i, j, k;

  printf("文字列を入力してください(長さ100以下): ");
  fgets(a, 100, stdin);

  for (j = 48; j < 58; j++) {

    k = 0;
    for (i = 0; a[i] != '\0'; i++) {
     if (a[i] == j)
       k = k + 1;
    }
     printf("%d は %d 個含まれています.\n", j - 48, k); 
  }

  return 0;
} 
