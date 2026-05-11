#include <stdio.h>
#define SIZE 256

void mystrcpy(char trg[], const char src[]);
void mystrcat(char trg[], const char src[]);
int mystrlen(const char trg[]);
int mystrcmp(const char* s1, const char* s2);

int main(void)
{
  char tar[SIZE] = "hoge";
  char src[SIZE] = "piyo";
  char cmp[SIZE] = "fuga";

  printf("test mystrcpy()\n");
  printf("(tar[], src[]) = (%s, %s)\n", tar, src);
  mystrcpy(tar, src);
  printf("(tar[], src[]) = (%s, %s)\n", tar, src);
  printf("\n");

  printf("test mystrcat()\n");
  printf("(tar[], src[]) = (%s, %s)\n", tar, src);
  mystrcat(tar, src);
  printf("(tar[], src[]) = (%s, %s)\n", tar, src);
  printf("\n");

  printf("test mystrlen()\n");
  printf("strlen(%s), %d\n", tar, mystrlen(tar));
  printf("\n");

  printf("test mystrcmp()\n");
  printf("strcmp(%s, %s), %d\n", tar, cmp, mystrcmp(tar, cmp));
  printf("\n");

  return 0;
};

void mystrcpy(char trg[], const char src[])
{
  int i;
  int s;	/* size of src[] */

  s = mystrlen(src);

  for(i=0; i<=s; i++)
    trg[i] = src[i];
};

void mystrcat(char trg[], const char src[])
{
  int i;
  int t, s;	/* size of trg[], src[] */

  t = mystrlen(trg);
  s = mystrlen(src);

  for(i=0; i<=s; i++){
    trg[t] = src[i];
    t++;
  }
};

int mystrlen(const char trg[])
{
  int count;

  for(count=0; /* count < MAX_SIZE */ ; count++)
    if(trg[count] == '\0')
      return count;

  /* strlen() search '\0' all over memory */
  /* if trg[] don't have '0' */
  //return -1;
};

int mystrcmp(const char* s1, const char* s2)
{
  int i;

  for(i=0; /* i < MAX_SIZE */; i++){
    if(s1[i] > s2[i])
      return 1;
    else if(s1[i] < s2[i])
      return -1;
    else if(s1[i] == '\0' || s2[i] == '\0')
      return 0;
  }

  //return ERROR_CODE;
};
