#include <stdio.h>

void mystrcpy(char str1[],char str2[]);
void mystrcat(char str1[],char str2[]);
int mystrlen(char str1[]);




int main(void)
{
  char str1[80], str2[80] ;
  
  

  printf("第1の文字列を入力してください: ");
  fgets(str1, 80, stdin);
  printf("第2の文字列を入力してください: ");
  fgets(str2, 80, stdin);

  mystrcpy(str1,str2);
  mystrcat(str1,str2);
  mystrlen(str1); 

  printf("第1の文字列に、第2の文字列をコピーした結果:%s", str1);
  printf("第1の文字列の後に第2の文字列をつなげたものは%s",str1);
  printf(" %sの文字列の長さは %d 文字です。",str1,mystrlen(str1)); 

  return 0;  

}

  /*str2をstr1にコピーする*/
  

 void mystrcpy(char str1[],char str2[])
  {
    int i ;
    
    for(i = 0; str1[i] !='\0'; i++ )
      str1[i] = str2[i] ;
   
  }

  
  /*str1の後尾にstr2をつなげる*/

void mystrcat(char str1[],char str2[])
{
    int i;
    int length = mystrlen(str1);

    for(i=0; str2[i] != '\0'; i++ )
{
  str1[i + length] = str2[i] ;
}
  str1[i + length] = '\0';


}    


/*str1の文字数を数える*/

int mystrlen(char str1[])
{
  int j;

  while(*str1++ != '\0')
{
  j++;
 }
 

  return j;
}
