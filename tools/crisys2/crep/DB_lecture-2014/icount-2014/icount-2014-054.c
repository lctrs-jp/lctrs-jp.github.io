#include<stdio.h>
#include<string.h>

int main()
{
  char text[101];
  int i, j, k, y;

  printf("数字列を入力してください(長さ100以下): ");
  fgets(text, 100, stdin);

  for(j = 0; j <= 9; j++){
    k = 0;
    for(i = 0;i <= strlen(text) - 1; i++){
      y = (int)text[i] - (int)'0';
      if(y == j){k++;}
    }
    printf("%dは %d個含まれています.\n", j, k);
  }
  return 0;
}
