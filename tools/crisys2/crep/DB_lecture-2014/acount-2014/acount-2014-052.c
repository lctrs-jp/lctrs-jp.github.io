#include <stdio.h>
#include <string.h>

int main ()
{
  int i, j, k, l, count[26];
  char max[27], str[101];

  for (i = 0; i < 26 ; i++) count[i] = 0;

  printf("文字列を入力してください（100文字以下）:");
  fgets(str, 101, stdin);

  printf("\n");

  k = strlen(str);

  for (i = 0; i < 26; i++) {
    for (j = 0; j < k; j++) {
      if (str[j] == i + 65 || str[j] == i + 97)
        count[i]++;
    }
  }
  
  l = 0;
  for ( i = 0; i < 26; i++) {
    if (l <= count[i]) {
      l = count[i];
      max[i] = i + 97;
    }
  }


  printf("最瀕出文字は");
  for (i = 0; i = 26; i++) {
    if (max[i] != '0')
      printf(" %c", max[i]);
  }
  printf("\n");
  printf("出現回数は%d回\n", l);

    return 0;
}
