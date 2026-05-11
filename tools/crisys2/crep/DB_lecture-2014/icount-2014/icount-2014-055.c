#include <stdio.h>
#include <string.h>

int main()
{
  char str[100];
  int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int i;

  printf("数字列を入力してください。(長さ100以下)\n");
  fgets(str, 100, stdin);
  if( str[strlen(str) - 1] == '\n' )//改行対策
    str[strlen(str) - 1] = '\0';

  for(i = 0 ; i < strlen(str); i++)//判別
    {
      if(str[i] == '0')
	a[0] = a[0] + 1;
      else if(str[i] == '1')
	a[1] = a[1] + 1;
      else if(str[i] == '2')
	a[2] = a[2] + 1;
      else if(str[i] == '3')
	a[3] = a[3] + 1;
      else if(str[i] == '4')
	a[4] = a[4] + 1;
      else if(str[i] == '5')
	a[5] = a[5] + 1;
      else if(str[i] == '6')
	a[6] = a[6] + 1;
      else if(str[i] == '7')
	a[7] = a[7] + 1;
      else if(str[i] == '8')
	a[8] = a[8] + 1;
      else if(str[i] == '9')
	a[9] = a[9] + 1;
    }

  for(i = 0; i < 10; i++ )
    printf("%d は %d個含まれています。\n", i, a[i]);

  return 0;
} 
  
