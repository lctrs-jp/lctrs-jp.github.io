#include <stdio.h>
#include <string.h>

int main()
{
  char str[201];

  printf("判定する文字列を入力してください。(200文字以下)\n");
  fgets(str, 202, stdin);

  int i, j;
  int a[25];
  int win[25];

  /* a[]とwin[]の数値を0にする */
  for(i = 0; i < 26; i++)
    {
      a[i] = 0;
      win[i] = 0;
    }

  /* 先頭から順に数え上げ */
  for(i = 0; str[i] != '\0'; i++)
    {
      /* 指定の文字の数をカウント */
      for(j = 0; j < 26; j++)
	{
	  if(str[i] == ('a' + j ) || str[i] == ('A' + j ))
	    a[j] = a[j] + 1;
	}
    }


  /* 最も多い文字の判定 */
   for(i = 0; i < 26; i++)
    {
      for(j = 0; j < 26; j++)
	{
	if(a[i] >= a[j])
	  win[i] = win[i] + 1;
	}
    }


   /* 表示 */
   printf("最も多い文字は以下のようになる。\n");
     for(i = 0; i < 26; i++)
       {
	 if( win[i] == 26 )
	   printf("%c：%d回\n",'a' + i , a[i]);
       }

  return;
}





