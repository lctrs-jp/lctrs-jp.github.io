#include <stdio.h>

int main(void)
{
  int str[100], i, j, x, t;
  printf("アルファベットを入力してください: ");
  scanf("%c", &str[i]);
  x = 0;
  for (i = 0; str[i] != '\0'; i++) {
    for (j = 'a'; j >= 'a' && j<= 'z'; j++) {
      t = str[i];
      if (t = j)
	x = x +1;
    }
  }
 printf ("%d は %d 個", j, x);

 return 0;
}
