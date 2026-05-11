#include <stdio.h>
#include <math.h>
int main(void)

{
  float t[7], min, max, avg, h;
  int i;
    //一週間分の最高気温を入力してもらう
    for( i=0; i<7; i++ )
      {printf("%d日目の最高気温を入力してください：",i+1);
	scanf("%f", &t[i]);}


    //平均を求める
    avg=0;
    for(i=0; i<7; i++ )
      {avg=avg+t[i];}
	printf("平均：%f\n", avg/7);


    //最高・最低気温を求める
    min=200;
    max=0;
    for(i=0; i<7; i++ )
      {if(min>t[i])
	  min=t[i];
	if(max<t[i])
	  max=t[i];}

    printf("最高値：%f\n", max);
    printf("最低値：%f\n", min);


    //分散・標準偏差を求める
    h=0;
    for(i=0; i<7; i++ )
      {h=h+(t[i]-avg/7)*(t[i]-avg/7);}

    printf("分散：%f\n",h/7);
    printf("標準偏差：%f\n",sqrt(h/7));


    //中間値を求める
    int j, k;
    for(i=1; i<7; ++i )
    for(j=6; j>=i; --j){
      if(t[j-1] > t[j]){
	k=t[j-1];
	t[j-1] = t[j];
	t[j] = k;}}
    
    printf("中間値：%f\n",t[3]);

	  


    return 0;
}






















