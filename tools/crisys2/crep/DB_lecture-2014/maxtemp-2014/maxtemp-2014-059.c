#include<stdio.h>


int main(void)
{
  double temp[7],min,max,avg,x,s,m;
  int i,k; 
  int days=7;
    
  for(i=0;i<days;i++){
    printf("%d日の気温を入力して下さい",i+1);
    scanf("%lf",&temp[i]);
  }
  
  /*平均気温*/
  avg=0;
  for(i=0;i<days;i++)
    avg=avg+temp[i];
    printf("平均気温:%lf\n",avg/days);
  
  /*最低最高気温*/
  min=200;
  max=0;
  for(i=0;i<days;i++){
    if(temp[i] <min)
      min=temp[i];
    if(temp[i]>max)
      max=temp[i] ;
  }

  printf("最高気温:%lf\n",max);
  printf("最低気温:%lf\n",min);

  /*分散・標準偏差*/
  s=0;
 for(i=0;i<days;i++)
   s=s+(temp[i]-avg/days)*(temp[i]-avg/days);
     printf("分散:%lf\n",s/days);  
#include<math.h>
     x=s/days;
     double sqrt(double x);
       printf("標準偏差:%lf\n",sqrt(x));
  
  /*中央値*/
       for(i=0;i<days;++i){
	 for(k=days-1;k>=i;--k){
           if(temp[k-1]>temp[k]){
	       m=temp[k-1];
               temp[k-1]=temp[k];
               temp[k]=m;
             }
	 }
       }
       printf("中央値:%lf\n",temp[3]);
 
 return 0;
}
