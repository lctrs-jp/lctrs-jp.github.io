#include <stdio.h>

int main(void)
{
  char str[101];
  int i, cnt[26];
  for(i = 0; i < 26; i++)
    cnt[i] = 0;

  printf("文字列を入力してください（長さ100以下）: ");
  gets(str);

  for(i = 0; str[i] != '\0'; i++){
    if('A' <= str[i] && str[i] <= 'Z')
      cnt[str[i] - 'A']++;
    else if('a' <= str[i] && str[i] <= 'z')
      cnt[str[i] - 'a']++;
  }

  for(i = 0; i < 26; i++)
    printf("%c　は　%d個含まれています.\n", i + 65,  cnt[i]);

  return 0;
}
