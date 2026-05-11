#include <stdio.h>
#include <string.h>

#define l 101

int main(void)
{
  char str[l];
  int num[10] = {0};
  int i, j;

  printf("数字列を入力してください(長さ%d以下とする): ", l - 1);
  fgets(str, sizeof(str), stdin);
  fflush(stdin);

  for(i = 0; i < 10; i++){
    for(j = 0; str[j] != '\0'; j++){
      if(str[j] == 48 + i) 
	num[i]++;
    }
  }

  for(i = 0; i < 10; i++)
    printf("%d は %d個含まれています．\n", i, num[i]);

  return 0;
}
