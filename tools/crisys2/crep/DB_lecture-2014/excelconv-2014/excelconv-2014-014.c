#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int ans = 0;
  char *p;
  p = argv[1];
  /*入力が正しいか確認する*/
  if(argc != 2)
    printf("文字列を一つ入力してください\n");
  else if(*p < 'A' || *p > 'Z' || strlen(p) > 5 )
    printf("アルファベット大文字、最大5桁の範囲で入力してください\n");

  /*26進数から10進数に変換*/
  else {
    while(*p){
      ans = ans * 26 + *p - 64;
      p++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
  
    
