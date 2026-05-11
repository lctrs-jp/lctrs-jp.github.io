#include<stdio.h>

int main()
{
  int i,j;
  int k = 0;
  char str[256];
  char res[256];
  char trg[] = "0123456789";

  printf("数字のみ抜き出します。\n");
  printf("文字列を入力してください:");
  scanf("%s" ,str);
  for(i = 0;str[i] != '\0';i++)
    for(j = 0;j <= 9;j++)
      if(str[i] == trg[j]){
        res[k] = str[i];
        ++k;
    }
  printf("%s\n",res);

  return 0;
}
