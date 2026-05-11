#include<stdio.h>
#include<string.h>
int main()
{
  int i,j,a[25],k,l,max,n;
  char str[80];

  //それぞれの個数を調べるためa[k]=0を代入
  for(k=0;k<=25;k++)
    a[k]=0;


  printf("アルファベットを入力してください。(80文字以内)");
  fgets(str,80,stdin);//fgetsがstring.hなしでできるかどうかわからなかった。


  //アルファベットの個数を調べる
  for(i=0;str[i];i++)
    for(j=0;j<=25;j++)
      if(str[i]==65+j||str[i]==97+j)//または使用で大文字小文字関係なく数えられるように。
	a[j]=a[j]+1;


  //最大個数を求める
  max=a[0];
  for(l=1;l<=25;l++)
    if(max<=a[l])
      max=a[l];


  //一応最大個数が二個以上の時の対策。
  for(n=0;n<=25;n++)
    if(a[n]==max)
      printf("最も多く出た文字は%cで%d回です。\n",65+n,max);//大文字で返すように調整。
  //forが少し多め。もっと効率をよくしたい。

  return 0;
}
