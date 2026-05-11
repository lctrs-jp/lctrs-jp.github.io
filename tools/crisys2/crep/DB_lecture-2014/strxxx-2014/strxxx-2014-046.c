#include<stdio.h>
char s1[50],s2[50];
void mystrcpy();
int mystrcat();
int mystrlen();

int main(){
  printf("s1[]に文字列を50字以内で入力");
  gets(s1);
  printf("s2[]に文字列を50字以内で入力");
  gets(s2);
  mystrlen();
  mystrcat();
  mystrcpy();
  return 0;
}

void mystrcpy(){
  int a;
  printf("コピー");
  for(a=0;s2[a]!='\0';a++){
    s1[a]=s2[a];
  }
  s1[a] = '\0';
  printf("s1[]は%s",s1);
  printf("s2[]は%s",s2);
  return;
}

int mystrcat(){
  char s3[105];
  int c,d;
  printf("後につなげる");
  for(c=0;s1[c]!='\0';c++)
    {s3[c]=s1[c];
    }
  s3[c]=s2[0];
  for(d=1;s3[c+d]!='\0';d++)
    {s3[c+d]=s2[d];
    }
  printf("%s",s3);
  return 0;
}

int mystrlen(){
  int e,f;
  e=0;
  while(s1[e]!='\0'){
    e=e++;}
  printf("s1の文字数は%d",e);
  f=0;
  while(s2[f]!='\0'){
    f=f++;}
  printf("s2の文字数は%d",f);
  return 0;
}
