#include <stdio.h>
#include <math.h>

void Sort(double s[]); //aの配列を小さい順に整理
double Var(double ave1,double a1[7]); //分散の関数

int main()
{
  double a[7]; //最高気温の配列
  double b=0;
  double max; //最大値
  double min; //最小値
  double ave; //平均
  double var; //分散
  double dev; //標準偏差
  double med; //中央値
  int i;

  printf("一日の最高気温を、一週間分入力してください。（℃）\n");

  //データ入力＋合計計算
  for(i=0;i<7;i++)
    {
      printf("%d日目,",i+1);
      scanf("%lf", &a[i]);
      b=b+a[i];
    }

  Sort(a);

  printf("その一週間の最高気温の\n");

  max=a[6];
  printf("最大値は%lf度です。\n",max);

  min=a[0];
  printf("最小値は%lf度です。\n",min);

  ave=b/7;
  printf("平均は%lf度です。\n",ave);

  var=Var(ave,a);
  printf("分散は%lfです。\n",var);

  dev=sqrt(var);
  printf("標準偏差は%lfです。\n",dev);

  med=a[3];
  printf("中央値は%lf度です。\n",med);
}

void Sort(double s[])
{
  double c; 
  int i,j;

  for(i=0;i<7;i++)
    {
      for(j=6;j>i;j--)
	{
	  if(s[j]<s[j-1])
	    {
	      c=s[j];
	      s[j]=s[j-1];
	      s[j-1]=c;
	    }
	}
    }
}

double Var(double ave1,double a1[7])
{
  double var1;
  double d=0;
  int i;

  for(i=0;i<7;i++)
    {
      d=d+(ave1-a1[i])*(ave1-a1[i]);
    }
  var1=d/7;

  return var1;
}
