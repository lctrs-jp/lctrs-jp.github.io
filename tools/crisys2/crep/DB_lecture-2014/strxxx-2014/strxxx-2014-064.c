#include<string.h>

#include<stdio.h>
 /* 各関数のプロトタイプ宣言 */
void mystrcpy(char str1[] , char str2[]);
void mystrcat(char str1[] , char str2[]);
int mystrlen(char str1[]);


int main()
{
  char str1[80] , str2[80];
  int i;

  printf("第一の文字列を入力してください:");
  gets(str1);
  printf("第二の文字列を入力してください:");
  gets(str2);

  /*文字列の長さを確認する*/

  printf("%s は %d 文字の長さです\n" , str1 , mystrlen(str1));
  printf("%s は %d 文字の長さです\n" , str2 , mystrlen(str2));

  /*文字列を比較する*/

  i = strcmp( str1 , str2 ); 

  if(!i)
    printf("文字列は等しい\n");
  else if ( i <0 )
    printf("%s は %s より小さい\n" , str1 , str2);
  else
    printf("%s は %s より大きい\n" , str1 , str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/

  if((mystrlen(str1) + mystrlen(str2)) < 80) {

    mystrcat(str1 , str2);
    printf("%s\n" , str1);
}

  /* str2 を str1にコピーする*/

  mystrcpy(str1 , str2);
  printf("%s %s\n" , str1 , str2);

  return 0;
}

/*　strcpyと同じ関数の設定 */

void mystrcpy(char str1[] , char str2[])
{
  int a;

   for( a = 0; a < 80 ; a++)
     str1[a] = str2[a];
   }

/* strlenと同じ関数の設定 */

int mystrlen(char str1[])
{
  int b;

  for(b = 0 ; b < 80 ; b++){
    if(str1[b] == '\0')
      break;
  }
  return b;
}  

/* strcatと同じ関数の設定 */

void mystrcat(char str1[], char str2[])
{
  char c,d,e;
    c = mystrlen(str1);
    e = mystrlen(str2);

    for(d = 0; d < e + 1; d++){
      str1[c + d] = str2[d];
    }
} 
    
