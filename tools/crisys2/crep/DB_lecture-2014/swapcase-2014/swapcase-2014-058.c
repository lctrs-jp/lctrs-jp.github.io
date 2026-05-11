#include <stdio.h>

#define SIZE 256
#define GAP 32

void test(char* str);
void swapcase(char str[]);

int main(void)
{
  int i;
  char str[4][SIZE] = {"string", "STRING", "CamelStyle", "123aBc789"};

  // test swapcase()
  for(i=0; i<4; i++)
    test(str[i]);

  return 0;
}

void test(char* str)
{
  printf("swapcase(%s)\t= ", str);

  swapcase(str);
  printf("%s\n", str);

  return;
}

void swapcase(char str[])
{
  int i;

  for(i=0; str[i]!='\0'; i++)
    if('a' <= str[i] && str[i] <= 'z')
      str[i] -= GAP;
    else if('A' <= str[i] && str[i] <= 'Z')
      str[i] += GAP;

  return;
}
