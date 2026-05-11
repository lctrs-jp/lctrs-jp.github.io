#include <stdio.h>


int main()
{

  double x, y, bmi;

 printf("あなたの体重は？(kg):" );
 scanf("%lf" , &x );

 printf("あなたの身長は？(cm):");
 scanf("%lf", &y );

 bmi= x * 10000 / ( y * y );

   if ( bmi >= 30 )
     printf("あなたのBMIは %.1f (高度肥満)\n", bmi);

     else if ( bmi >= 25 )
       printf("あなたのBMIは %.1f (肥満)\n", bmi);

       else if ( bmi >= 18.5 )
	 printf("あなたのBMIは %.1f (標準)\n", bmi);

	 else
	   printf("あなたのBMIは %.1f (やせ)\n", bmi);

return 0;
}
	 
