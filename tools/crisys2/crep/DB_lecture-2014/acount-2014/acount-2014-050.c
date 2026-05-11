#include <stdio.h>

int main()
{
  printf ("文字列を入力してください")
  fgets (str, 100, stdin);

  for (i=0; i<26 ; i++){
    count = 0;
        j = i + 65;
        k = i + 97;

	for (l=0; str[l]!='\0'; l++){
          if (str[l] == j)
            count = count + 1;
	  if (str[l] == k)
            count = count + 1;
        }
  
       printf("入力された文字列中の最も出現回数の多い文字は%c出現回数は%d"               ,count) ;
  }
  return 0;
}
