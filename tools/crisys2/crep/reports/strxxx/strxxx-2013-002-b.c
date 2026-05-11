#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);
int mystrcmp(char trg[], char[]);

int l = 80;

int main(void)
{
  char str1[l], str2[l];
  int i;

  printf("Input a string: ");
  gets(str1);
  printf("Input another string: ");
  gets(str2);

  printf("The length of %s is %d.\n",str1,mystrlen(str1));
  printf("The length of %s is %d.\n",str2,mystrlen(str2));

  i=mystrcmp(str1,str2);
  if(!i)
    printf("These strings are equivalent.\n");
  else if(i<0)
    printf("%s is smaller than %s.\n",str1,str2);
  else
    printf("%s is greater than %s.\n",str1,str2);

  if ((mystrlen(str1)+mystrlen(str2))<l){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

void mystrcpy(char trg[], char src[])
{ 
  int a = mystrlen(src);
  int i;
  for(i = 0; i <= a; i++)
    trg[i] = src[i];
}

void mystrcat(char trg[], char src[]){
  if ((mystrlen(trg)+mystrlen(src))>l){
    printf("Error: %s cannot be connected with the last element of %s.\n",src,trg);
    return;
  }
 
  int a = mystrlen(trg);
  int b = mystrlen(src);
  int i;

  for(i = 0; i < b; i++)
    trg[a+i] = src[i];
}

int mystrlen(char trg[]){ 
  int i = 0;
  do{
    if(trg[i] == '\0')
      return i;
    ++i;
  }while(i < l);

  return 0;
 }

int mystrcmp(char trg[], char src[]){
  int a = mystrlen(trg);
  int b = mystrlen(src);

  return a-b;
}
