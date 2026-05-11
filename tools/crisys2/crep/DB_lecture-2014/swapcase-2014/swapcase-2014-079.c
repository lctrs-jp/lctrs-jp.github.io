#include <stdio.h>
#include <string.h>
void swapcase(char str[]);

int main(void) {

  char str[255];
  int i;

  printf("文字列を入力してください:");
  fgets (str, 255, stdin);

  for(i = 0;i <= strlen(str); i++) {
    if ( str[i] >= 97 & str[i] <= 122) {
      str[i] = str[i] - 32 ;
    }
    else if ( str[i] >= 65 & str[i] <= 90) {
      str[i] = str[i] + 32 ;
    }
    printf("%c", str[i]);
  }
  return 0;
}
