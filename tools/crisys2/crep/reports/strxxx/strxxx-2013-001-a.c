#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystlen(char trg[]);

int main(void)
{
  return 0;
}

void mystrcpy(char trg[], char src[])
{
  int i;
  for(i = 0; src[i] != '\0'; i++)
    trg[i] = src[i];
}

void mystrcat(char trg[], char src[])
{
  int i, x;
  for(i = 0; trg[i] != '\0'; i++)
    x = i;
  for(i = 0; src[i] != '\0'; i++)
    trg[x + i] = src[i];
}

int mystlen(char trg[])
{
  int i, x;
  for(i = 0; trg[i] != '\0'; i++)
    x = i;
  return x;
}
