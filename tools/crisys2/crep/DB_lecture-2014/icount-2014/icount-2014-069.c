#include<stdio.h>

int main()
{
  int a , b , i;
  char str[100];

  printf("文字を入力してください(長さ100以下)\n");
  scanf("%s" , str);
  /*各桁の数字で振り分け*/
  for(i = 0 ; i < 10; i++){
    a = 0; /*その数の個数の初期化*/ 
    for(b = 0; str[b] != '\0'; b++){
      if((str[b] - 48) == i) 
        a = a + 1;/*個数を増やしていく式*/
    } 
  
    printf("%d は %d 個含まれています。\n", i , a);
  }
    return 0;
  }
