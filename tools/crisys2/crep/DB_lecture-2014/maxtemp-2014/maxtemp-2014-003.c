#include <stdio.h>
#include <math.h>

int main(void)
{
  float a[7],temp,ave,sum=0.0,sum2=0.0,dev=0.0;
  int i,j,k;
  printf("input the tempratures\n");
  for(i=0;i<7;i++){  
    scanf("%f",&a[i]);
    sum += a[i];
    sum2+= a[i]*a[i];


  }

  for(j=0;j<6;j++){
    for(k=6;k>j;k--){
      if(a[k-1]>a[k]){
	temp=a[k-1];
	a[k-1]=a[k];
	a[k]=temp;
      }
    }
  }
  ave=sum/7;
  dev=sqrt(sum2/7-ave*ave);

  printf("MAX %f\nmin %f\nAve %f\nDev %f\nBun %f\nmid %f\n",
	 a[6],
	 a[0],
	 ave,
	 dev,
	 dev*dev,
	 a[3]);


  return 0;
}
