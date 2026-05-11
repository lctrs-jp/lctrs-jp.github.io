#include <string.h>
#include <stdio.h>


void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);      
int mystrlen(char trg[]);      


int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第１の文字列を入力してください: ");
  gets(str1);
  printf("第2の文字列を入力してください: ");
  gets(str2);

  /*文字列の長さを確認する*/
  printf("%s は %d 文字の長さです\n", str1, strlen(str1)); 
  printf("%s は %d 文字の長さです\n", str2, strlen(str2)); 

  /*文字列を比較する*/
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/
  if ((strlen(str1) + strlen(str2)) < 80) {
    strcat(str1, str2);
    printf("%s\n", str1);
  }

  /*str2をstr1にコピーする*/
  strcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;  
} 

void mystrcpy(char trg[], char src[]){
 
  int i;
  
  for(i = 0; src[i] != '\0'; i++){
    trg[i] = src[i];
  }
  for(; trg[i] !='\0'; i++){
    trg[i] = '\0';
  }

}


void mystrcat(char trg[], char src[])      

{
  int i, j;
 
  for(i = 0; trg[i] !='\0'; i++);
  for(j = 0; src[j] !='\0'; j++){
    trg[i] = src[j];
  }
}


int mystrlen(char trg[])      

{   
  int i;

  for(i = 0; trg[i] !='\0'; i++);

  return i;

}

