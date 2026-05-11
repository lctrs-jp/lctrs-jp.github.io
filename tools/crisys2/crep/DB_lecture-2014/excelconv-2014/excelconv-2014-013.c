#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[] )
{
  char *str = argv[1];
  int i,sum = 0  ;
  if(argc == 2){ 
    for(i = 0; i < strlen(str) ; i++)
    sum = sum * 26 + (str[i]-64);
    
  printf("%d\n", sum );
  }
  else
    printf("入力の仕方が違います：\n 例：./excel 大文字アルファベット５桁まで");

  return 0;
}





