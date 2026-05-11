#include <string.h>
#include <string.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[],char src[]);
int mystrlen(char trg[]);

int main()
{
  char str1[80], str2[80];
  int i;
  printf("第１の文字列を入力してください: ");
  gets(str1);
  printf("第２の文字列を入力してください: ");
  gets(str2);

  /*文字列の長さを確認*/
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /* スペースがあるなら str2をstr1の最後に連結 */

  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  /*str2をstr1にコピー*/

  mystrcpy(str1,str2);
  printf("%s %s\n", str1, str2);
 
  return 0;
}


/*文字列を入力して、長さを返す*/
int mystrlen(char trg[])
{
  int j = 0;

  while (trg[j] != '\0' ) {
    j++;
  }
  return j;
}

/*2つの文字列を与え、trgの後にsrcを付けたものを返す*/
void mystrcat(char trg[], char src[])
{
  int i, j;
  i = mystrlen(trg);
  for ( j = 0; src[j] != '\0' ; j++)
    {
      trg[i] = src[j];
      i++;
    }
  trg[i] = '\0';
  return;

}

/* 文字列をコピー*/

void mystrcpy(char trg[], char src[])
{
  int i;

  /*srcをtrgにコピー*/
  for ( i = 0 ; src[i] != '\0' ; i++ ){
    trg[i] = src[i];
  }
  trg[i] = '\0';
  return;
}
