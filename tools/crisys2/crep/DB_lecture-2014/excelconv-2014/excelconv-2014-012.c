#include <stdio.h>

int excelconv(char *s);

int main(int argc, char *argv[])
{
  printf("%d\n", excelconv(argv[1]));

  return 0;
}

int excelconv(char *s)
{
  int num = 0;

  while(*s) {
    num = num * 26 + (*s - 'A' + 1);
    s++;
  }

  return num;
}

