#include <stdio.h>

int main()
{
  char x[51];
  int i, j, count[26], max = 0;

  for (i=0; i<26; i++)
    count[i] = 0;

  printf("アルファベットを入力してください（50文字以下）: ");
  scanf("%50s",x);

  for (i=0;x[i] != '\0';i++)
    {

      for (j='a';j<='z'; j++) /* 文字を数えるループ*/
	{
	  if ((x[i] == j) || (x[i] == j - ('a'-'A'))) /*文字をaから順に調べる*/
	    {
	      count[(int)(j - 'a')] = count[(int)(j-'a')]+1; /*countに1を足す*/
	      break;
	    }
	}
    }

  for (i=0; i<26; i++) /* 最大個数を調べる*/
  {
    if (max<count[i])
      max = count[i];
  }


  printf("出現回数が多かった文字: ");
  for (i=0; i<26; i++) /* 最大個数の文字を表示する*/
    {
        if (count[i] == max){
	printf("%c ",(char)(i+'a'));
	}
    }
  printf("\n出現回数: %d\n",max);
  return 0;
}
