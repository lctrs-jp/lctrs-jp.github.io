#include<stdio.h>

int main()
{
  char str[100];
  int i,j,k;

  printf("文字列を入力:");
  fgets(str,100,stdin);

  for(i = 0; i < 10; i++) {
    k = 0;
    for( j = 0; str[j]!='\0'; j++) {
      if(str[j]==49+i) {
	k++;
      }
    }
    printf("%dは%d含まれています。\n",i,k);
  }

  return 0;
}
