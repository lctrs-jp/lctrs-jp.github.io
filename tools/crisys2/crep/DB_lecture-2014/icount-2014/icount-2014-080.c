#include <stdio.h>
#include <string.h>

int main()
{
  char str[80];
  int i,n;
  int num[10]={0,0,0,0,0,0,0,0,0,0};

  printf("数字列を入力してください。");
  fgets(str,80,stdin);

  for(i=0; i < strlen(str); i++){
    for(n=0; n<10; n++){
      if(str[i]==n+48)
	num[n]++;
    }
  }
  for(i=0;i<10;i++)
    printf("%dは%d個\n",i,num[i]);
  return 0;
}
