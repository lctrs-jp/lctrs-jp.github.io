#include <stdio.h>
#include <string.h>


int main(void)
{
  char inputs[101];
  int i;
  int counts[26];
  int answer;


  printf("文字列を入力してください(長さ100以下): ");
  fgets(inputs, 101, stdin);


  /* countsの初期化 */
  for (i = 0; i < 26; i++) {
    counts[i] = 0;
  }


  /* 入力した文字のカウント */
  for (i = 0; i < strlen(inputs); i++) {
    if ('a' <= inputs[i] && inputs[i] <= 'z')
      counts[inputs[i] - 'a']++;

    else if ('A' <= inputs[i] && inputs[i] <= 'Z')
      counts[inputs[i] - 'A']++;
  }


  answer = counts[0];
  for (i = 0; i < 26; i++) {
    if (answer <= counts[i])
      answer = counts[i];
  }


  for (i = 0; i < 26; i++) {
    if (counts[i] == answer)
	  printf("最頻出文字は %c\n ", i+'a');
  }
  printf("出現回数は %d回", answer);

  return 0;
}
