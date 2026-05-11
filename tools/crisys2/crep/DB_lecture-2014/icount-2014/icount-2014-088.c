#include<stdio.h>

int main(void)
{
  char str[100];
  int count[10];
  int n,i,j;

  for( i = 0 ; i < 10 ; i++ ){
    count[i] = 0;
  }

  printf("数字列を入力してください。（長さ１００以下）:");
  scanf("%s", str );
  for( i = 0 ; str[i] ; i++){
    for( j = 48 ; j <= 57 ; j++){
      if(str[i] == j)
        count[j-48]+=1;
    }
  }

  for( n = 0; n <= 9 ; n++)
    printf("%dは%d個含まれています。\n", n , count[n]);

  return 0;
}
