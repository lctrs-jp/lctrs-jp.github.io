#include <string.h>
#include <stdio.h>

char mystrlen(char *co)
{
  int i;
  i = 0;

  while(*(co+i) != '\0'){
    i++;
  };

  return i;
}

void mystrcpy(char trg[80], char src[80])
{
  int i;
  for( i = 0; src[i] != '\0'; i++){
    trg[i] = src[i];
  }
  trg[i] = '\0';
}

void mystrcat(char deat[], char source[])
{
  int i;
  int len = mystrlen(deat);

  for(i = 0; source[i] != '\0'; i++) {
    deat[i + len] = source[i];
  }
  deat[i + le] = '\0';
}
  

  for(i = 0; i < 80; i++){
    if(stg1[i] = 0){
      for(j = 0; stg2[j]; j++, i++){
      stg1[i] = stg2[j];
      }
  }
}
}

/*
 if(strlen(stg2) > strlen(stg1)){
1[i] = stg1[i] + stg2[i];
    */  


int main(void)
{
  char str1[80], str2[80], u;
  int m;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  //文字列の長さを確認する
  printf("%sは%d文字の長さです\n", str1, mystrlen(str1));
  printf("%sは%d文字の長さです\n", str2, mystrlen(str2));

  //文字列を比較する
  m = strcmp(str1, str2);
  if (!m)
    printf("文字列は等しい\n");
  else if (m < 0)
    printf("%sは%sより小さい\n", str1, str2);
  else
    printf("%sは%sより大きい\n", str1, str2);

  /*  //十分なスペースがあれば、str2をstr1の最後に連結する
  if ((mystrlen(str1) + mystrlen(str2)) < 80){
     mystrcat(str1, str2);
     printf("%s\n", str1);
    }
  */

  mystrcat(str1, str2);
  printf("%s\n", str1);

  // str2をstr1にコピーする
   mystrcpy(str1, str2);
   printf("%s %s\n", str1, str2);

    return 0;
    }
