#include <string.h>
#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);             
int mystrcmp(char trg[], char src[]); 

int main(void)
{
  char str1[80], str2[80];
  int i, len1, len2;

  printf("Input a string: ");
  gets(str1);
  printf("Input another string: ");
  gets(str2);

  len1 = mystrlen(str1);
  len2 = mystrlen(str2);
  printf("The length of %s is %d.\n", str1, len1);
  printf("The length of %s is %d.\n", str2, len2);

  i = mystrcmp(str1, str2);
  if(!i)
    printf("These strings are equivalent.\n");
  else{
    if(i < 0)
      printf("%s is smaller than %s.\n", str1, str2);
    else
      printf("%s is greater than %s.\n", str1, str2);
  }

  if(len1 + len2 < 80){
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

void mystrcpy(char trg[], char src[]){
  int i;

  for(i = 0; src[i] != '\0'; i++)
    trg[i] = src[i];

  trg[i] = '\0';
}

void mystrcat(char trg[], char src[]){
  int i, len;

  len = mystrlen(trg);

  for(i = 0; src[i] != '\0'; i++)
    trg[i + len] = src[i];

  trg[i + len] = '\0';
}

int mystrlen(char trg[]){
  int i, len = 0;

  for(i = 0; trg[i] != '\0'; i++)
    len++;

  return len;
}

int mystrcmp(char trg[], char src[])
{
  return mystrlen(trg) - mystrlen(src);
}
