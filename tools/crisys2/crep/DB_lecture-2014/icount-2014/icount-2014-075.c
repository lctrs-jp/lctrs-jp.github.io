#include <stdio.h>
#include <string.h>

int main(void)
{
  char aaa[101];
  int b,c,e,d[10]={0,0,0,0,0,0,0,0,0,0};

  printf("長さ100以下の数字を入力してください :");
  scanf("%s",aaa);
    
  for(b=0; b < 100; b++){
    for(c=0; c <=9; c++){
      if(aaa[b]==c+48){
	d[c]=d[c]+1;
      }}}
  for(e=0; e<=9; e++)
    printf("%d は%d 個あります\n",e, d[e]);
  
  
  return 0;
}
