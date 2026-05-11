#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, n = 0  ;
  
  for(i = 0; argv[1][i] !='\0'; i++);/* 文字数を数える */
  if( i > 5){
      printf("六文字以上になってます\n");
      return ;}
  else  {
  if( argc == 2 ){/* 引数が一つ存在する時 */
    for( i = 0; argv[1][i] !='\0'; i++){
      if( argv[1][i] < 'A' && 'Z' < argv[1][i] )
	return 0;/* 大文字以外があるとき終了 */
      else
      n = n * 26 + (argv[1][i] - 'A'+ 1);
    }
    printf("%d\n", n );
  }
  return 0;}
}
