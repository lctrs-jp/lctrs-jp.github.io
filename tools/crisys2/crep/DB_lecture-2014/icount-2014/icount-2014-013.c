#include <stdio.h>

int main()
{
  char str[100];
  int i, j, count;
  char num ='0';
  
  printf("数字列を入力してください(長さ100以下):");
  scanf("%s", str);
  /*個数を数える*/
  for( j = 0; j < 10; j++){
    count = 0;
    for( i = 0; str[i]; i++){
	if(str[i] == num )
	count++; 
    }
    printf("%d は %d 個含まれています\n", j, count );
    num++; 
  }
  return 0;
}
