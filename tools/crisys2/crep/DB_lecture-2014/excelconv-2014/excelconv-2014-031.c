#include <stdio.h>
#include <string.h>

int exchg_26_10 (char *c);

int main(int argc, char *argv[])
{
  int i, j;
  char ch[5];
  
  if (argc != 2 || strlen(argv[1]) > 5){
    printf("引数が異常です\n");
    return 0;
  }
  
  i = strlen(argv[1]);
  j = i;

  while (*argv[1] != '\0') {       /* 便宜上、26進数の一桁が最初になるように並び替える */
    if (i > 0){
      ch[i - 1] = *argv[1]++;
      i--;
    }
  }
   ch[j] = '\0';
   
  printf("%d\n", exchg_26_10(ch));
  return 0;
}



int exchg_26_10(char *c)
/* 桁の繰り上がりを、n進数のとき、x個のnと扱い、10進数に変換する関数 */
{
  int a = 'A' - 1, alpha = 26;

  if (*(c + 1) == '\0'){
    return (*c - a);
  }
  else if (*(c + 1) != '\0'){
    return (*c - a) + alpha * (exchg_26_10(c+1)); /* 再帰を使って、2桁目、3桁目に、26を塁上してかける */
  }						  /* イメージ　26*(26*(... = 26^n + 26^(n-1) + ... */
  return 0;			/* 警告抑制 */
}
