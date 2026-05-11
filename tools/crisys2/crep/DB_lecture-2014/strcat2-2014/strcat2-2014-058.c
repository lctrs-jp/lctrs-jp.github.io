#include <stdio.h>
void mystrcat(char *to, char *from)

;int main(void)
{
  char s1[100];
  char s2[100];

  printf("先頭の文字列\n");
  fgets(s1, 100, stdin);

  printf("末尾の文字列\n");
  fgets(s2, 100, stdin);

  mystrcat(s1, s2);

  printf("%s", s1);

  return 0;
}

void mystrcat(char *to, char *from)
{
  while(*(to + 1))
	  *to++;

  while(*from)
	  *to++ = *from++;

  *to = '\0';
}
