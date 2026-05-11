#include <stdio.h>

void swapcase();

int main()
{
  char str[80];

  printf("80文字以内の文字列を入力してください\n");
  fgets(str,80,stdin);

  swapcase(str[80]);

  return 0;
}

void swapcase(char str[80])
{
  int i;

  for(i=0 ; str[i] != '\0' ; i++)
    {
      if(str[i] <= 'Z' && str[i] >= 'A')
	{
	  str[i] = str[i]+('a'-'A');
	}else{
	  if(str[i] <='z' && str[i] >='a')
	    {
	      str[i] = str[i]+('A'-'a');
	    }}}
  return ;
}
