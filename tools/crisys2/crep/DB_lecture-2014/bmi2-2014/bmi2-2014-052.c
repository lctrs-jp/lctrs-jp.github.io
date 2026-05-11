#include <stdio.h>
float bmi;
int main ()
{
	
	float height;
	int weight;
	

	printf("How tall are you? (m)\n");
	scanf("%f", & height );

	printf("What is your weight? (kg)\n");
	scanf("%d", & weight);


	bmi = weight / height / height;

	if (bmi < 18.5)
		printf("あなたのBMIは%4.2fでやせです。\n",bmi);
	else if (18.50 <= bmi < 25.00)
		printf("あなたのBMIは%4.2fで普通です。\n",bmi);
	else if (25.00 <= bmi < 30.00)
		printf("あなたのBMIは%4.2fで肥満です。\n",bmi);
	else
		printf("あなたのBMIは%4.2fで高度肥満です。\n",bmi);
	return 0;
}