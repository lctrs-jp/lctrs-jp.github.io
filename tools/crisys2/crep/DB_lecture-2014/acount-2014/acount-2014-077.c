#include <stdio.h>

int main()
{
  char moji[101];
  int i, j, abc[26];

  for ( i = 0; i < 26; i++ )
    abc[i] = 0;

  printf("文字を入力して下さい(長さ100 以下) : ");
  fgets(moji, 101, stdin);

  for ( j = 0; j < 26; j++) 
    for ( i = 0; moji[i] != '\0'; i++){
      if ( moji[i] == j + 'a')
	abc[j] = abc[j] + 1;
      if ( moji[i] == j + 'A')
	abc[j] = abc[j] + 1;
    }

  for ( i = 100; i > 0; i--)
    for ( j = 0; j < 26; j++)
      break;

  printf("最出現文字は、");
  for ( j = 0; j < 26; j++)
    if ( abc[j] == i )
      printf("%s ", j + 'a');
  printf("です。\n");

  printf("出現回数は、%d です。", i);

  return 0;
}
