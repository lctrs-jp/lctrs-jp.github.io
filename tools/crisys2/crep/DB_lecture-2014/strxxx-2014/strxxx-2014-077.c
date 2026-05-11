#include <string.h>
#include <stdio.h>

void mystrcpy(char s1[80] , char s2[80]);
void mystrcat(char s1[80], char s2[80]);
int mystrlen(char str[80]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第１の文字列を入力してください:");
  fgets(str1,80,stdin);
  printf("第２の文字列を入力してください:");
  fgets(str2,80,stdin);

  printf("%s は %d-1 文字の長さです\n",str1,mystrlen(str1));
  printf("%s は %d-1 文字の長さです\n",str2,mystrlen(str2));

  i = strcmp(str1, str2);
  if(!i)
    printf("文字列は等しい");
  else if (i<0)
    printf("%s は %s より小さい\n",str1,str2);
  else 
    printf("%s は %s より大きい\n",str1,str2);

  if((mystrlen(str1)+mystrlen(str2))<80) {
    mystrcat(str1,str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n", str1,str2);

  return 0;
}




void mystrcpy(char s1[80] , char s2[80])
{
 int i;

 for( i = 0; s2[i] != '\0'; i++ ) {
   s1[i] = s2[i];
   }
   s1[i] = '\0';
}
void mystrcat(char s1[80], char s2[80])
{
 int i;
 int len = strlen( s1 );

 for( i = 0; s2[i] != '\0'; i++ ) {
  s1[ i + len ] = s2[i];
   }
  s1[i + len] = '\0';
}
int mystrlen(char str[80])
{
  int i = 0;

  for( i = 0; str[i] != '\0'; i++ );
  
return i;
}




