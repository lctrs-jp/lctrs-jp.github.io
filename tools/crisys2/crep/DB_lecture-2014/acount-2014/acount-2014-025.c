#include<stdio.h>
#include<string.h>

int kazoeru(char str[i]);
char saihin(char str[i]);

int main()
{
  printf("文字列を入力してください(長さ100以下)\n");

  char str[101];
  int x;

  fgets(str, 101, stdin);//文字列を受け取る

  x=kazoeru(char str[101]);

  saihin(char str[101]);
  printf("出現回数は%dです\n",x);
}

int kazoeru(char str[i]);
{
  int i,j,a,b,t,atoz[27]; //A~Zが入る入れ物を用意
  for(j = 0; j < 27;j++) atoz[j] = 0;//初期化

  for(i = 0; str[i] != 0 ;i++){
    if('A' <= str[i] && str[i] <= 'Z'){//大文字の時
      atoz['str[i]'-'A'] ++;
    }
    else
      if('a' <= str[i] && str[i] <= 'z'){//小文字の時
	atoz['str[i]'-'a'] ++;
      }
  }
  //atozの0~25にアルファベットの各回数が入った
  //それを並べ替える↓
  //バブルソート
  for(a = 1;a < 27;a++){
    for(b = 26;b >= a; b--){
      if(atoz[b-1]>atoz[b]){
	t=atoz[b-1];
	atoz[b-1]=atoz[b];
	atoz[b]=t;
      }
    }
  }
  return atoz[26];
}



char saihin(char str[i])
{
  int i,j,a,b,t,k,atoz[27]; //A~Zが入る入れ物を用意
  for(j = 0; j < 27;j++) atoz[j] = 0;//初期化

  for(i = 0; str[i] != 0 ;i++){
    if('A' <= str[i] && str[i] <= 'Z'){//大文字の時
      atoz['str[i]'-'A'] ++;
    }
    else
      if('a' <= str[i] && str[i] <= 'z'){//小文字の時
        atoz['str[i]'-'a'] ++;
      }
  }

  //atoz[26]と同じ数字を探す
  for(k=0; str[k] != 0; k++){
    if(atoz[k] = kazoeru(i)){
      c=srt[k]

