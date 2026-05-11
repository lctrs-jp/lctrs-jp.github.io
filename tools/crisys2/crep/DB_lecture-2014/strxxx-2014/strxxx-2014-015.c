#include<stdio.h>
int mystrlen(char trg[]);//文字の長さを求める関数の宣言
int mystrcmp(char trg[], char src[]);//辞書の順番を求める関数の宣言
void mystrcat(char trg[],char src[]);//文字の後ろにコピーする関数の宣言
void mystrcpy(char trg[], char src[]); //文字をそのままコピーする関数
int main()
{
  char str1[80],str2[80];
  int i;
  //文字の読み取り
  printf("第一の文字列を入力してください。");
  gets(str1);
  printf("第二の文字列を入力してください。");
  gets(str2);
  //文字の長さを求める
  printf("%sは%d文字の長さです。\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです。\n",str2,mystrlen(str2));
  //辞書順でどうか調べる
  i=mystrcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else 
    printf("%sは%sより大きい\n",str1,str2);

  //長さ的にどうか調べる。
  if((mystrlen(str1)+mystrlen(str2)) <80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }
  //文字をコピーする
  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);
  return 0;
}
//文字をコピーする関数
int mystrlen(char trg[]) 
{
  int i;
  char dam[80];
  for(i=0;trg[i];i++)
    dam[i]=trg[i];//ダミーにコピーする量で求める
  return i;
}

//文字の大きさを調べる関数
int mystrcmp(char trg[], char src[])
{
  int a,b,i,k,l;
  int m=0;
  a=mystrlen(trg);
  b=mystrlen(src);
  if(a < b)
    k=a;
  else if(a > b)
    k=b;
  else if(a==b)
    k=a;
  for(i = 0 ;i < k;i++){
    if(trg[i] > src[i]){
      l=1;
      break;
    }
    else if(trg[i] <src[i]){
      l=-1;
      break;
    }
    else if(trg[i]==src[i])
      m=m+1;
    if(m==k&&a<b){
      l=-1;
      break;
    }
    else if(m==k&&a>b){
      l=1;
      break;
    }
    else if(m==k&&a==b){
      l=0;
      break;
    }}
  return l;//こんなに長い必要があったのか。
}
//後ろにコピーする
void mystrcat(char trg[],char src[])
{
  int i,k;
  k=mystrlen(trg);
  for(i=k;src[i-k];i++)
    trg[i]=src[i-k]; 
  return;
}
//コピーする
void mystrcpy(char trg[],char src[])
{
  int i;
  for(i=0;i<80;i++)
    trg[i]=src[i];
  return;//文字数を求める関数とコピーする関数
        //後ろにコピーする関数を一緒にできなかったものか。

}
