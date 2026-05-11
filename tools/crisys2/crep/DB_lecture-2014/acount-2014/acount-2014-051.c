#include <stdio.h>
#include <string.h>

int main()
{
  char str[128];
  int i, j, k, count, oldcount, len;
  char ch, oldch;

  printf("文字列を入力してください:");
  fgets(str, 128, stdin);

  //大文字が入力されたら小文字にする
  for(k = 0; str[k] != '\0'; k++)
    if('A' <= str[k] && str[k] <= 'Z')
      str[k] = str[k] + ('a' - 'A');

  len = strlen(str);

  oldcount = 0;

  for(i = 0; i < len; i++) {
    ch = str[i];
    count = 1;

    for(j = i + 1; j < len; j++)
      if(ch == str[j])
	count++;

    if(count > oldcount) {
      oldch = ch;
      oldcount = count;
    }
  }

  printf("最も出現回数の多い文字は %c です\n", oldch);
  printf("その出現回数は %d です", oldcount);

  return 0;
}

