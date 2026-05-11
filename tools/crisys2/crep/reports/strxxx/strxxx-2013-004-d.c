#include <string.h>
#include <stdio.h>

void mystrcpy(char x[], char y[]);
void mystrcat(char x[], char y[]);
int mystrlen(char x[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("Input a string: ");
  fgets(str1 ,80 ,stdin);
  printf("Input anther string: ");
  fgets(str2 ,80 ,stdin);
  
  printf("The length of %s is equivalent to %d.\n", str1, mystrlen(str1));
  printf("The length of %s is equivalent to %d\n", str2, mystrlen(str2));

  i = strcmp(str1, str2);
  if (!i)
    printf("These strings are equivalent.\n");
  else if (i < 0)
    printf("%s is smaller than %s.\n", str1, str2);
  else
    printf("%s is greater than %s.\n", str1, str2);

  if((strlen(str1) + strlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

void mystrcpy(char x[], char y[])
{
  for(int i=0 ; i < strlen(x) ; i++) x[i] = y[i];
}

void mystrcat(char x[], char y[])
{
  int t = 0;
  for(int i=0 ; i < 80 ; i++) {
    if (t == 0) if ((int) x[i] == 0) t = i;
    if (t!=0) x[i] = y[i-t];
  }
}

int mystrlen(char x[])
{
  int t = 0;
  for(int i=0 ; i < 80 ; i++) {
    if ((int) x[i] == 0) {t = i; break;}
  }

  return t;
}
