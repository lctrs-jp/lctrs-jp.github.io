#include<stdio.h>
#include<string.h>
int mychange(char t[]);/*プロトタイプ宣言*/
int power(int a,int n);/*同上*/

int main()
{

  char alp[1024];
  int pl;

  printf("大文字のアルファベットを入力してください(A〜ZZZZZまで):");
  scanf("%s",&alp);

  pl= mychange(alp);

  if(strlen(alp)>5) /*5文字以上を入力されたらエラーを返す*/
    {
      printf("Try again\n");
    }

  else
    printf("%d\n" , pl);

  return 0;
}

int mychange(char t[]){

  char *p = t;
  int a = 0;
  int b = strlen(t);
  /*再帰を用いる*/
  if(b==1)
    { 
	a = ((int) (*p) - 64) * (power(26,b -1));
        return a;
    }
  else
    {
      return ((int) (*p) - 64) * (power(26,b -1)) + mychange(p+1);

    }
  return ;
}

int power(int a,int n)/*べき乗を計算する関数を定義する*/
{
  int num = 1;
  int i;

  for(i = 0;i < n;i++)
    num = num * a;

  return num;
}