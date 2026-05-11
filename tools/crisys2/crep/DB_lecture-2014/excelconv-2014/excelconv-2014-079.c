#include<stdio.h>
int main(void)
{
  char str[10];
  int i,j;//jが10進数の数字
  printf("文字列を大文字の英数五文字以内で入力してください\n");
  scanf("%s",str);
  i = strlen(str);
  if(i == 5)
      j = (str[0] - 64)*26*26*26*26+(str[1] - 64)*26*26*26+(str[2] - 64)*26*26+(str[3] - 64)*26+(str[4] - 64)*1;
    else if (i == 4)
      j = (str[0]-64)*26*26*26+(str[1]-64)*26*26+(str[2]-64)*26+(str[3]-64)*1;
    else if (i == 3)
      j = (str[0]-64)*26*26+(str[1]-64)*26+(str[2]-64)*1;
    else if (i == 2)
      j = (str[0]-64)*26+(str[1]-64)*1;
    else if (i == 1)
      j = (str[0]-64)*1;
    printf("結果：%d\n",j);
    return 0;
}
