#include <stdio.h>

void mystrcat(char *p,char *q);

int main(void)
{
  char a[200];
  char b[100];

  printf("100文字以内の文字列を入力してください。\n");
  fgets(a,100,stdin);

  printf("もう一つ、100文字以内の文字列を入力してください。\n");
  fgets(b,100,stdin);

  mystrcat(a,b);
  printf("二つの文字列をつなげると、\n%s\nになります。",a);

  return 0;
}

void mystrcat(char *p,char *q)
{
  int len;
  int i,j;

  for(i=0;*(p+i) != '\0';i++)
    len=i+1;  

  for(j=0;*(q+j) != '\0';j++)
    *(p+len+j)=*(q+j);
}
