#include <stdio.h>
#include <string.h>

int main()
{
  int i, j, k, l;
  char c[100];

  printf("100文字以内の数字列を入力してください:");
  fgets(c, 100, stdin);

  l = strlen(c);

  for (i = 0; i < 10; i++){
    k = 0;
    for (j = 0; j < l; j++){
      if (c[j] == i + 48)
	k = k + c[j] / (i + 48);
    }
	printf("%d は %d 個含まれています\n", i, k);
  }

  return 0;
}
