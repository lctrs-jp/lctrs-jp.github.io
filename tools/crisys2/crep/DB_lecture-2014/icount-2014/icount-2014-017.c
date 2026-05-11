#include<stdio.h>
int main(void)
{
  int i,k,j;
  int a[10]={0,0,0,0,0,0,0,0,0,0};//すべてにゼロ代入forループでもできた。
  char str1[100];
  printf("文字列を入力してください。");
  gets(str1);
  for(i=0;str1[i]!='\0';i++){
    for(j=0;j<=9;j++){
      if(str1[i]==48+j)//asciiコード使用
	a[j]=a[j]+1;
    }}
  for(k=0;k<=9;k++)
    printf("%dは%d個含まれています。\n",k,a[k]);
  return 0;
}
