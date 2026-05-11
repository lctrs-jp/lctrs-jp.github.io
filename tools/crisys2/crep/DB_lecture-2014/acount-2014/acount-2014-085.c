#include <stdio.h>

int main(void)
{
  char str[100];
  int i, n[10], j, max, m;

  printf("文字列を入力してください : ");
  fgets(str, 100, stdin);

  for (j = 'a'; j <= 'z'; j++) {
    n[j] = 0;
    for (i = 0; str[i] != '\0'; i++) {
      if ('A' <= str[i] && str[i] <= 'Z')
	n[str[i] + ('a' - 'A')]++;
      else {
         if ('a' <= str[i] && str[i] <= 'z')
	   n[str[i]]++;
      }
    }
    }  
    max = 0;
    for (j = 'a'; j <= 'z'; j++) {
      if (max < n[j]) {
	max = n[j];
        m = j;
      }
    }
  
    printf("最頻出文字は %c : %d 回\n", m, max);

  return 0;
}
