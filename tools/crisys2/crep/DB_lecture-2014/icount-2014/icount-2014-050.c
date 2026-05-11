#include<stdio.h>
int main()
{char a[101];
  int b,c,d;
  printf("数字列を100字以内で入力してくださいな\n");
  gets(a);
  for(c=0;c!=10;c++){
    d=0;
    for(b=0;a[b]!='\0';b++){
      if(a[b]==(char)c+48)
	d++;}
    printf("%dは%d個含まれています",c,d);}
      return 0;}
