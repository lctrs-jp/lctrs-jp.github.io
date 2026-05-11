#include<stdio.h>
#include<math.h>
int main()
{int a,h;
  double b,kion[7],c,min,max,d,e,f,i,g;
  printf("7日間の最高気温を打ち込んでください");
    for(a=0;a<7;a++)
      {scanf("%lf",&kion[a]);
      }
    b=0;
    for (a=0;a<7;a++)
      {b=b+kion[a];
      }
    c=b/7;
    printf("平均最高気温は%lf",c);
    min=200;
    max=0;
    for(a=0;a<7;a++){
      if(min>kion[a])
	min=kion[a];
    }
    for(a=0;a<7;a++){    
      if(max<kion[a])
	max=kion[a];
    }
    printf("最高気温の最大値は%lf",max);
    printf("最高気温の最小値は%lf",min);
    d=0;
    for(a=0;a<7;a++){d=d+(kion[a]-c)*(kion[a]-c);}
    e=d/7;
    printf("分散は%lf",e);
    f=sqrt(e);
    printf("標準偏差は%lf",f);
    for(a=1;a<7;++a){
      for(h=6;h>=a;--h){
	if(kion[h-1]>kion[h]){
	g=kion[h-1];
	kion[h-1]=kion[h];
      kion[h]=g;}
      }
    }
    i = kion[3];
    printf("中央値は%lf", i );
    return 0;
}
