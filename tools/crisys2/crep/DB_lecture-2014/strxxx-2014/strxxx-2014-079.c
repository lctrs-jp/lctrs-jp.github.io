#include <stdio.h>
#include <string.h>

void mystrcpy(char trg[] , char src[]);
void mystrcat(char trg[] , char src[]);
int mystrlen(char trg[]);
int main(void)
{
  char str1[80], str2[80];
  int i;
  
  printf("第一の文字列を入力して下さい: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);
  //文字列の長さを確認する  
  printf("%sは %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%sは %d 文字の長さです\n", str2, mystrlen(str2));

  //文字列を比較する
  i = strcmp(str1, str2);
  if(!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else 
    printf("%s は %s より大きい\n", str1, str2);

  //十分なスペースが有ればstr２の値をstr１の最後に連結する
  if(( mystrlen(str1) + mystrlen(str2)) < 80){
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }
  
  //str2をstr１にコピーする
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

void mystrcpy(char trg[] , char src[]){
  int i;
  for( i = 0; src[i] != '\0' ; i++){
      trg[i] = src[i];
  }
  for( ; trg[i] != '\0' ; i++){
    trg[i] = '\0';
  }
  return;
}

void mystrcat(char trg[] , char src[]){
  int i,k;
  for( i = 0; trg[i] !='\0' ; i++);
  for( k = 0; src[k] !='\0' ; k++){
    trg[i] = src[k];
    i++;
  }
  for( ; trg[i] != '\0' ; i++){
    trg[i] = '\0';
  }
  return;
}

int mystrlen(char trg[]){
  int i;
  for( i = 0; trg[i] !='\0' ; i++);
  return i;
}
  


    
