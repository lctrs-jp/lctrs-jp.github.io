#include <stdio.h>

int main(void)
{
  int i, j, k, l;
  int a[26];
  int max = 0;
 
  char word[101];

  printf("文字列を入力してください（長さ100以下）\n");
  fgets(word, 101, stdin);

  for(i = 0; word[i + 1] != '\0'; i++){
    for(j = 0; j != 25; j++){
      if(word[i] == 65 + j || word[i] == 97 + j)
        a[j]++;
    }  
  }

  for(k = 0; k != 26; k++){
    if(max < a[k])
      max = a[k]; 
  }

  for(l = 0; a[l] != max; l++)
    ;    
  
  printf("最頻出の文字は %c で %d個です。", l + 'a', max);

  return 0;
}
