#include <string.h>
#include <stdio.h>

void mystrcpy(char a[80],char b[80]);

void mystrcat(char a[80],char b[80]);

int mystrlen(char a[80]);

int main(void)
{
  char str1[80],str2[80];
  int i;

  printf("第１の文字列を入力してください: ");
  fgets(str1,80,stdin);
  printf("第２の文字列を入力してください: ");
  fgets(str2,80,stdin);
  
  str1[mystrlen(str1)-1]='\0' ;
  str2[mystrlen(str2)-1]='\0' ;
  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n",str1,mystrlen(str1));
  printf("%s は %d 文字の長さです\n",str2,mystrlen(str2));

  /* 文字列を比較する */
  i = strcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if (i<0)
    printf("%s は %s より小さい\n",str1,str2);
  else 
    printf("%s は %s より大きい\n",str1,str2);

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
    mystrcat(str1,str2);

  /* str2をstr1にコピーする */
  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

void mystrcpy(char a[], char b[])
{
  int i;
  for (i=0;a[i]||b[i];i++){
    a[i] = b[i];}
}

int mystrlen(char a[]){
  int i,t;
  for(i=0;a[i];i++){
    t=i+1;
      }
  return t;
    }
void mystrcat(char a[], char b[]){
  char x[160];
  int i,j,p,q,t;
  p=mystrlen(a);
  q=mystrlen(b);
    if(p+q <=160){
      for(i=0;a[i];i++){
	x[i]=a[i];
	t=i;
      }
      for(j=0,i=t;b[j];j++){
	x[i+j+1]=b[j];
      }
      printf("%s\n",x);
    }
    else{
      printf("error\n");
	}
}

      
