#include<stdio.h>
#include<string.h>

/*以下三つは関数の定義*/

void mystrcpy(char trg[] , char src[]) 
{
  int i;

  for( i = 0; src[i] != '\0'; i++ ) {
    trg[i] = src[i];
  }
  trg[i] = '\0';
}

void mystrcat(char trg[] , char src[])
{

    int i;
    int len = mystrlen( trg );

    for( i = 0; src[i] != '\0'; i++ ) {
      trg[i+len] = src[i];
    }
    trg[i+len] = '\0';
  }

int mystrlen(char trg[])
{
  int i = 0;

  for( i = 0; trg[i] != '\0'; i++ );

  return i;
}

int main()

{
  char str1[80] , str2[80] , a , b ;
  int i;

  printf("第一の文字列を入力してください:");
  fgets(str1 , 80 , stdin);
  printf("第二の文字列を入力してください:");
  fgets(str2 , 80 , stdin);

  /*文字列の長さを確認する*/
  a =  mystrlen(str1)-1;
  b =  mystrlen(str2)-1;
  printf("%sは%d文字の長さです\n" , str1 , a);
  printf("%sは%d文字の長さです\n" , str2 , b);

  /*文字列を比較する*/
  i = strcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
 else if(i < 0)
    printf("%sは%sより小さい\n" , str1 , str2);
 else
    printf("%sは%sより大きい\n" , str1 , str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/
  if( (mystrlen(str1) + mystrlen(str2)) < 80)
 {
    mystrcat(str1,str2);
    printf("%s\n" , str1);
  }

  /*str2をstr1にコピーする*/
  mystrcpy(str1 , str2);
  printf("%s%s\n" , str1 , str2);


  return 0;
}



