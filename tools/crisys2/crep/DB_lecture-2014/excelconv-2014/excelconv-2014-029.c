#include <stdio.h>
#include <math.h>

int conv(int a, int b, char *s); //文字列を26進法から10進法に直して返す。
void error(void); //エラー表示

int main(int argc, char *argv[])
{
  int i=0;
  int sum=0;

  if(argc != 2)
    error();
  else
    sum=conv(sum,i,argv[1]);

  //値が消されていなければ、値を表示する。
  if(sum != 0)
    printf("引数の文字列を26進数ととらえて10進数に直すと、%dになります。",sum);

  return 0;
}

int conv(int a, int b, char *s)
{
  int i;

  //はじめだけ、bの値を最大桁に合わせて、つじつまを合わせる。
  if(b==0)
      for(i=0;*(s+i) != '\0';i++)
	b++;

  if(b>5) //もし文字数が6つ以上だったら、エラー表示＋値を消す。
    {
      error();
      a=0;
    }
  //文字列の初めから、null文字までの文字を26進法に直して加算していく。
  else if(*s >= 'A' && *s <= 'Z')
    {
      b--;
      a=a+(*s-'A'+1)*pow(26,b);
      s++;
      a=conv(a,b,s);
    }
  else if(*s != '\0') //もしAからZ以外の文字があったら、エラー表示＋値を消す。
    {
      error();
      a=0;
    }

  return a;
}

void error(void)
{
  printf("引数の値が適切ではありません。AからZZZZZまでの間で入力してください。　プログラムを終了します。");
}
