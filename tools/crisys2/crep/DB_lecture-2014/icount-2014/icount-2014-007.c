#include <stdio.h>
#include <string.h>

int main()
{
  char j,word[100];
  int count, n, i, k, len;

  printf("文字を入力してください:"); /* 文字列の入力する */
  fgets(word, 100, stdin);

  len = strlen(word);
  
  /* 文字数の計算する */ 
 for(j = 48 ; j <= 57 ; j++)
   {
     count = 0; 
     for(i = 0; word[i] != '\0'; i++)
       if(word[i] == j)
	 {
	   count++;
	 }
     
     printf("%c は %d 個含まれています。\n", j, count);
   }

 return 0; 
}
