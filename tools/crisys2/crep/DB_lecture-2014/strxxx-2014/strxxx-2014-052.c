#include<stdio.h>
#include<string.h>
void mystrcpy(char trg[],char src[]);
void mystrcat(char trg[],char src[]);
int mystrlen(char trg[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください:");
  gets(str1);
  printf("第二の文字列を入力してください:");
  gets(str2);

  /*文字列の長さを確認*/
  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));

  /*文字列の文字数を比較*/
  i=strcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);
  
  /*十分なスペースがあればstr2をstr1の最後に連結*/
  if((mystrlen(str1)+mystrlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }
  
  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

/*コピー関数などなどの定義*/
void mystrcpy(char trg[],char src[])
{
  int l;
  for(l=0;l<80;l++){
    trg[l]=src[l];
  }
  
}

void mystrcat(char trg[],char src[])
{
  int j,x;
  j=mystrlen(trg);
  x=0;
  while(j<80,x<80){
    trg[j]=src[x];
    j++;
    x++;
  }
}  

  


int mystrlen(char trg[])
{
  int k;
  k=0;
  while(trg[k]){
    k++;
  }
  return k;
}
