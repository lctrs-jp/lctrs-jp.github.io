#include <stdio.h>

int main()
{
  char str[100];
  int i,j,k,n;

  printf("数字列を入力してください（長さ100以下）:");
  gets(str);
  for( j=0;j<10;j++){
    n = 0;
    k = j + 48;
    for(i = 0;str[i] != '\0';i++){
      if(str[i] == k)
        n++;
    }
    printf("%dは%d個あります\n",j,n);
  }
  return 0;
}
