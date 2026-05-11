#include<stdio.h>
 
int main()
{
  int i,count,j;
  char a[100];
  printf("文字列を入力してください:");
  gets(a);

  for(i=48,count=0;i<58;i++){
    for(j=0;a[j]!=0;j++)
      if(a[j]==i)
	count++;
    printf("%dは%d個です\n",i-48,count);
    count = 0;
  }
  return 0;
}
