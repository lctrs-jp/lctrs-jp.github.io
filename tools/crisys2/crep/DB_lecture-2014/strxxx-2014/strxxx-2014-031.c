#include <stdio.h>
#include <string.h>

/* function */
void mystrcpy(char trg[], char src[]);

void mystrcat(char trg[], char src[]);

int mystrlen(char trg[]);

int main(void)
{
  char ch[100];
  char cp[100];
  int i;

  /* 結果 */
  gets(ch);
  strcpy(cp,ch);
  printf("%s\n", cp);
  mystrcpy(cp, ch);
  printf("%s\n", cp);

  strcat(cp, ch);
  printf("%s\n", cp);
  mystrcat(cp, ch);
  printf("%s\n", cp);

  i = strlen(ch);
  printf("%d\n", i);
  i = mystrlen(ch);
  printf("%d\n", i);

  return 0;
}

/*function define*/
void mystrcpy(char trg[], char src[])
{
  int i;

  for (i = 0; src[i] != '\0' ; i++){
    trg[i] = src[i];
  }

  return ;
}

void mystrcat(char trg[], char src[])
{
  int i;
  int c;

  /* 最後端を特定する */
  for (i = 0; trg[i] != '\0' ; i++){
    c = i + 1;
  }

  /* 特定した最後端にsrcを付け足す */
  for (i = 0; src[i]; i++){
    trg[c + i] = src[i];
  }
  return ;
}

int mystrlen(char trg[])
{
  int i;
  int c;

  for (i = 0; trg[i] != '\0'; i++){
    c = i + 1;
  }
  return c;
}


/* もしくは、定義関数内でstrcat,strlen,strcpyを使う */
