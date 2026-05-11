#include <stdio.h>

void sub(double a);

int main()
{
    int w;
	double h;
	
	printf("体重(kg)を入力してください\n");
	scanf("%d",&w );
	printf("身長(m)を入力してください\n");
	scanf("%lf",&h );
	sub(w/(h*h));
	return 0;
}

void sub(double a)
{
	printf("あなたのBMIは\n");
	
	if( a >= 30 )
	  printf("%.2lf(高度肥満)\n",a );
	if( a < 30 && a >= 25)
	  printf("%.2lf(肥満)\n",a );
	if( a < 25 && a >= 18.5 )
	  printf("%.2lf(標準)\n",a );
	if( a <18.5  )
	  printf("%.2lf(やせ)\n",a );
}	
