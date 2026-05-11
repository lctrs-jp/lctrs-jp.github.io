#include<stdio.h>

void mystrcpy(char a[], char b[]);
void mystrcat(char a[], char b[]);
int mystrlen(char a[]);
int mystrcmp(char a[], char b[]);

int main()
{
  char str1[80], str2[80];
  int i;
  
  printf("第一の文字列を入力してください:");
  gets(str1);
  printf("第二の文字列を入力してください:");
  gets(str2);

  //文字列の長さを確認する
  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));

  //文字列を比較する
  i = mystrcmp(str1,str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%sは%sより小さい\n", str1, str2);
  else
    printf("%Sは%Sより大きい\n", str1, str2);
  
  //十分なスペースが有れば、str2をstr1の最後に連結する
  if(mystrlen(str1)+mystrlen(str2)<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  //str2をstr1にコピーする
  mystrcpy(str1,str2);
  printf("%s %s\n", str1, str2);
  
  return 0;
}

//配列をコピーする関数
void mystrcpy(char a[], char b[]){
  int i;
  for(i = 0;;i++){
    a[i] = b[i];
    if(a[i] == '\0')
      break;
  }
}

//配列を末尾にコピーする関数
void mystrcat(char a[],char b[]){
  int k,j;
  for(k=0;;k++)
    if(a[k] == '\0')
      break;

  for(j=0;;j++,k++){
    a[k] = b[j];
    if(a[k] == '\0')
      break;
  }
}

//文字列の長さを計算する関数
int mystrlen(char a[]){
  int i;
  for(i=0;;i++)
    if(a[i]=='\0')
      break;
  return i;
}

//2つの文字列を先頭から比較する関数
int mystrcmp(char a[],char b[]){
  int i;
  for(i=0;;i++){
    if((a[i] == '\0')&&(b[i] == '\0')){
      return 0;
    }
    else if(a[i] > b[i]){
      return 1;
    }
    else if(b[i] > a[i]){
      return -1;
    }
  }
}
