#include<stdio.h>
#include<string.h>
int count(int k, char a[100]);

int main(void)
{
  int k;
  char a[100];
    printf("数字列を入力してください（長さ100文字以内）: ");
    fgets(a, 100, stdin);
    for(k = 0; k < 10; k++)
    printf("%d は %d個含まれています。\n", k, count(k,a)); 
    return 0;
}

int count(int k , char scr[100])
{
  int j, l;
  j = 0;
      for(l = 0; scr[l] != '\0'; l++)
	if(scr[l] == k + 48) /* 0のASCIIコードは48なので48をASCIIコードに追加する */
	  j++;/* 等しいときに出力値を1つ増やす */

  return j;   
}
