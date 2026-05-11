#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[101];
  int t[10]={0};
  int i,j;

  printf("数字列を入力してください(長さ100以下): ");
  fgets(s, sizeof(s), stdin);
  fflush(stdin);

  for(i=0;i<10;i++){
    for(j=0;s[j]!='\0';j++){
      if(s[j]==48+i) 
	t[i]++;
    }
  }

  for(i=0;i<10;i++)
    printf("%d は %d個含まれています\n",i,t[i]);

  return 0;
}
