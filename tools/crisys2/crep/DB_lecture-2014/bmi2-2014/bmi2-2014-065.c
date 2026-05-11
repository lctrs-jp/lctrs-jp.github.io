#include <stdio.h>
float B(float x, float y); /*ユーザ定義関数Bのプロトタイプ宣言*/

;int main()
{
	float w;
	float t;

	printf("体重を入力してください\n");
	scanf("%f", &w );

	printf("身長を入力してください\n");
	scanf("%f", &t );

	if( w / ( t * t ) < 18.5 )
		printf("BMI = %f (やせ)", B(w, t) );
	else if( w / ( t * t ) < 25 )
		printf("BMI = %f (標準)", B(w, t) );
	else if( w / ( t * t ) < 30 )
		printf("BMI = %f (肥満)", B(w, t) );
	else
		printf("BMI = %f (高度肥満)", B(w, t) );

	return 0;
}

float B(float x, float y) /*Bの本体*/
{
	float z;

	z = x / ( y * y );

	return z;
}

