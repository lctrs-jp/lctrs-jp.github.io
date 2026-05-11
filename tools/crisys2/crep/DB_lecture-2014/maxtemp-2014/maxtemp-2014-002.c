#include<stdio.h>
#include<math.h>

int main()
{
  printf("7日分の最高気温を入力してください\n");
  
  int i;
  float a[7];

  for(i=1;i<8;i++){
    printf("%d) : ",i);
    scanf("%f",&a[i-1]);
  }

  float max;   //最大値
  float min;   //最小値
  float aver;   //平均
  float stand;   //標準偏差   
  float disper;   //分散
  float middle;   //中央値

  max = a[0];
  min = a[0];
  for(i=0;i<6;i++){   //最大値
    if(max<a[i+1]){
      max = a[i+1];
	}
  }
  for(i=0;i<6;i++){   //最小値
    if(min>a[i+1]){
      min = a[i+1];
	}
  }     

  float sum=0;
  for(i=0;i<7;i++){   //合計値
    sum = sum+a[i];
    }
	
	aver = sum / 7;   //平均
	
	float u=0;
	for(i=0;i<7;i++){
		u = u + pow(a[i] - aver,2);
		}
	disper = u / 7;   //分散
	stand = sqrt(disper);   //標準偏差
	
	float v[7];
	for(i=0;i<7;i++){
		 v[i] = fabs(aver - a[i+1]); 
		 if(v[i] < v[i+1]) middle = a[i];
	}	
	printf("\n");
	printf("結果\n");
	printf("最高値: %.2f\n",max);
	printf("最小値: %.2f\n",min);
	printf("平均: %.2f\n",aver);
	printf("標準偏差: %.2f\n",stand);
	printf("分散: %.2f\n",disper);
	printf("中央値: %.2f\n",middle);
	printf("\n");
	
	return 0;

}
