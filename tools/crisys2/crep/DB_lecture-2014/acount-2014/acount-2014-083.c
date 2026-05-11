#include <stdio.h>
#include <string.h>

int main ()
{

  int i, j, t;
  char str[100];
  int count[26], sub[26];
 
  printf("文字列を入力してください。(長さ100以下) : ");
  scanf("%s", &str);

  for(i = 0; str[i] != '\0' ; i++)
    {
      for(j = 0; j <= 26; j++)
	{
	  if(str[i] == j+65 || str[i] == j+97)
	    count[i]++;
	}
    }
 
  for(i = 0; i < 26; i++)
    sub[i] = count[i];

  //バブルソートを利用して最大値を探す
  for(i = 0; i < 25; i++)
    {
      for(j = i + 1; j < 26; j++) 
	{
	  if(sub[i] > sub[j])
	    {
	      t = sub[i];
	      sub[i] = sub[j];
	      sub[j] = t;
	    }
	}
    }

  printf("最頻出文字は ");
  for(i = 0; i < 26; i++)
    {
      if(count[i] == sub[25])
	printf("%s", str[i]);
    }
  printf("\n出現回数は %d回", sub[25]);

    return 0;
}
