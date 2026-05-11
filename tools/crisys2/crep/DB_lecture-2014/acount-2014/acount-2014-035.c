#include <stdio.h>
#include <string.h>

int main(void)
{
  char retu[101];
  int a,c,i,d[10] = {0,0,0,0,0,0,0,0,0,0};  
  printf("文字列を入力してください(長さ100以下)\n");
  fgets(retu, 101, stdin);

  for(a = 0; a < 101; a++){
    for(c=0; c <= 101; c++){
      if(retu[a] <= 122 && retu >= 97){
	d[c] = d[c] + 1;
      }}}
  for(i = 0; i < 101; i++)
    printf("%d は %d 個あります",i,d[i]);

  return 0;
}
