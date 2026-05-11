#include <stdio.h>
void upcase(char str[]);

int main(void)
{
  char word[101];

  printf("文字列を入力してください（長さ100以下）\n");
  fgets(word, 101, stdin);

  upcase(word);

  printf("%s", word);

  return 0;
}

void upcase(char str[])
{
  int i;

  for(i = 0; str[i + 1] != '\0'; i++){
    if(str[i] > 96 && str[i] < 123)
      str[i] = str[i] - 32;
  }
} 
