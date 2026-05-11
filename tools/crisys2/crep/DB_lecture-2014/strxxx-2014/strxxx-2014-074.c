#include <stdio.h>
#include<string.h>
/*mystrcpy関数*/
void mystrcpy(char *trg, char *src){
  while(*trg++ = *src++)
    ;
}  

/*mystrcat関数*/
 void mystrcat(char *trg, char *src){
   while(*trg)
     trg++;
   while(*trg++ = *src++)
     ;
  }

/*mystrlen関数*/
int mystrlen(char *trg){
  char *p = trg;
  while(*p)
    p++;
  return p -trg;
}


/*5.2-1の実行*/
int main(void)
{
  char str1[80],str2[80];
  int l;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  /*文字列の長さを確認する*/
  printf("%s は　%d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は　%d 文字の長さです\n", str2, mystrlen(str2));

  /*文字列を比較する*/
  l = strcmp(str1,str2);
  if (!l)
    printf("文字列は等しい\n");
  else if (l < 0)
    printf("%s は　%s より小さい\n",str1,str2);
  else
    printf("%s は %s より大きい\n",str1,str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/
  if ((mystrlen(str1) + strlen(str2))<80) {
      mystrcat(str1,str2);
      printf("%s\n",str1);
    }

    /*str2をstr1にコピーする*/
    mystrcpy(str1,str2);
    printf("%s %s\n",str1,str2);

    return 0;  
}
 
