#include <stdio.h>
#include <string.h>

int main()
{
  char str[101];
  int i, j, k, t;
  int ko[26], bub[26];

  char moji;
  int kai;

  printf("文字列を入力してください(長さ100以下): ");
  fgets(str, 100, stdin);
  
  for(i = 0; i <= 25; i++){
    ko[i] = 0;
    bub[i] = 0;
  }
  
  for(i = 0; i <= strlen(str) - 1; i++){
    for(j = 0; j <= 25; j++){
      if(str[i] == 'A' + j)
	ko[j]++;
    }
  }

  for(i = 0; i <= strlen(str) - 1; i++){
    for(j = 0; j <= 25; j++){
      if(str[i] == 'a' + j)
        ko[j]++;
    }
  }

  for(i = 0; i <= 25; i++)
    bub[i] = ko[i];

  for(i = 1; i < 26; i++)
    for(k = 25; k >= i; k--){
      if(bub[k-1] > bub[k]){
	t = bub[k-1];
	bub[k-1] = bub[k];
	bub[k] = t;
      }
    }

printf("最頻出文字は");

  for(i = 0; i <= 25; i++){
    if(ko[i] == bub[25]){
      printf(" %c", i + 'a');
    }
  }
  printf("\n");
  
  printf("出現回数は%d回\n", bub[25]);

  return 0;
}
