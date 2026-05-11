#include<stdio.h>
#include<math.h>

int main(void)
{
 double kion[6];
  int n;
  for(n=0;n<7;n++){
    printf("10月%d日気温:",n+1);
    scanf("%lf",&kion[n]);
  }
  double sum = 0;
  for(n=0;n<7;){
    sum = sum + kion[n];
    n++;
}

  printf("Average:%lf\n", sum/7);
  
 double max = 0, min = 200;
  for(n=0;n<7;n++){
    if(kion[n]< min)
      min = kion[n];
    if(kion[n]>max)
      max =kion[n];
  }
  printf("Max:%lf\n", max);
  printf("min:%lf\n", min);

    double dis=0;
    for(n=0;n<7;){
      dis = dis + (kion[n]-(sum/7))*(kion[n]-(sum/7));
      n++;
    }
    printf("Dispersion:%lf\n", dis/7);
    printf("Deviation:%lf\n",sqrt(dis/7));

    int m;
    double tmp;
    for(n = 0;n < 6;n++){
      for(m = n +1; m<7 ;m++)
	if(kion[n] < kion[m]){
	    tmp = kion[n];
	    kion[n] = kion[m];
	    kion[m] = tmp;
	  }
    }

      printf("Median:%lf\n",kion[3]);
  return 0;
}

 
