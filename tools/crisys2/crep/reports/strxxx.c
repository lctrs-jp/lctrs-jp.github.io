#include <string.h>
#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);
int mystrcmp(char trg[], char src[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("Input a string: ");
  gets(str1);
  printf("Input another string: ");
  gets(str2);

  printf("The length of %s is %d.\n", str1, mystrlen(str1));
  printf("The length of %s is %d.\n", str2, mystrlen(str2));

  i = mystrcmp(str1, str2);
  if (!i)
    printf("These strigs are equivalent.\n");
  else if (i < 0)
    printf("%s is smaller than %s.\n", str1, str2);
  else
    printf("%s is larger than %s.\n", str1, str2);

  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

void mystrcpy(char trg[], char src[])
{
  int i;

  for( i = 0 ; src[i] != '\0' ; i++ )
    trg[i] = src[i];
  trg[i] = '\0';

  return;
}

void mystrcat(char trg[], char src[])
{
  int i, j;

  for( i = 0; trg[i] != '\0' ; i++ );

  for( j = 0 ; src[j] != '\0' ; j++ ){
    trg[i] = src[j];
    i++;
  }

  trg[i] = '\0';

  return;
}

int mystrlen(char trg[])
{
  int len = 0;
  while( trg[len] != '\0' ){
    len ++;
  }
  return len;
}

int mystrcmp(char trg[], char src[])
{
  int i;

  for( i = 0 ; trg[i] == src[i] ; i++ ){
    if( trg[i] == '\0' ) break;
  }

  return trg[i] - src[i];
}
