#include <stdio.h>
#include <string.h>

int mystrlen(char trg[]);
int mystrcmp(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
void mystrcpy(char trg[], char src[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列:");
  fgets(str1, 80, stdin);
  printf("第二の文字列:");
  fgets(str2, 80, stdin);

  printf("%sは%d文字の長さです\n", str1, mystrlen(str1));
  printf("%sは%d文字の長さです\n", str2, mystrlen(str2));

  i = mystrcmp(str1, str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i < 0)
    printf("%sは%sよりも小さい\n", str1, str2);
  else
    printf("%sは%sよりも大きい\n", str1, str2);

  if((mystrlen(str1) + mystrlen(str2)) < 80){
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

int mystrlen(char trg[])
{
  int i = 0;
  while(trg[i] != '\0'){
    i++;
  }
  return i;
}

int mystrcmp(char trg[], char src[])
{
  int i = 0, t = 1;
  while(trg[i] == src[i]){
    if(trg[i] == '\0'){
      if(src[i] == '\0'){
	t = 0;
	break;
      }
    }
    i++;
  }

  if(t != 0){
    if(mystrlen(trg) < mystrlen(src)){
      t = -1;
    }
    else if(mystrlen(trg) > mystrlen(src)){
      t = 1;
    }
    else{
      if(trg[i] < src[i]){
	t = -1;
      }
      if(trg[i] > src[i]){
	t = 1;
      }
    }
  }

  return t;
}

void mystrcat(char trg[], char src[])
{
  int i = 0, t = 0;
  while(trg[i] != '\0'){
    i++;
  }
  while(src[i] != '\0'){
    trg[i] = src[t];
    i++;
    t++;
  }
  trg[i] = '\0';
}

void mystrcpy(char trg[], char src[])
{
  int i = 0;
  while(src[i] != '\0'){
    trg[i] = src[i];
    i++;
  }
  trg[i] = '\0';
}
