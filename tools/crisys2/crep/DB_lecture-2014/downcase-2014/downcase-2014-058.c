#include <stdio.h>
void downcase(char str[]);

int main(void)
{
  int a;
  char word[100];

  printf("文字を入力してください\n");
  fgets(word, 100, stdin);

  downcase(word);

  printf("%s", word);

  return 0;
}

void downcase(char str[])
{
  int i;
  for(i = 0; str[i + 1] != '\0'; i++) {
    if ('[' > str[i] && str[i]  > '@')
      str[i] = str[i] + 32;
  }
}
