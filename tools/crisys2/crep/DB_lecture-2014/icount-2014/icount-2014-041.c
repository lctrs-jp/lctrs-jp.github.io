#include<stdio.h>
int main(void)
{
  char s[100];
  int c[10];
  int a,i,j;

    for(i=0; i < 10 ; i++){
     c[i]=0
       ;}

  printf("数字列を入力してください。");
  scanf("%s",s);
  for(i=0;s[i];i++){
    for(j=48;j<=57;j++){
      if(s[i]==j){
	c[j-48]+=1;
      }}}
  for(a=0;a<=9;a++)
    printf("%dは%d個含まれています。\n",a,c[a]);
  return 0;
}
