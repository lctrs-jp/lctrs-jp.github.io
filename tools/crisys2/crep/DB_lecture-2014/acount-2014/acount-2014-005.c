#include <stdio.h>
 
int main()
{
  char str[51];
  int i,j,k,n,max;

  printf("文字列を入力してください:");
  gets( str );
  max = 0 ;
  for( j='a';j <='z';j++){
      n = 'a';
      k = j + 'z';
      for(i = 0;str[i] != '\0';i++){
	if(str[i] == k)
	  n++;
        if (max < n)
	  max = n;   
      }
      printf("%dが最大個数%d個あります\n ", j, n);
    }
  return 0;
}
