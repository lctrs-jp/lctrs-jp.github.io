#include <stdio.h>
int main ()
{
	float height;//変数定義
	int weight;
	float bmi;

	printf("How tall are you? (m)\n");
	scanf("%f", & height );//身長入力

	printf("What is your weight? (kg)\n");
	scanf("%d", & weight);//体重入力

	bmi = weight / height / height;
	printf("Your BMI is %4.2f\n",bmi );

	return 0;
}