
/* BMIの計算 */
#include <stdio.h>


int main()
{
 float weight, height; /* 身長と体重を格納する変数 */

 /*体重の入力*/
 printf("体重を入力してください(kg)");
 scanf("%f", &weight);

 /*身長の入力*/
 printf("身長を入力してください(m)");
 scanf("%f", &height);

 /* BMIの計算と表示 */
 printf("\n体重%fkg、身長%fmの人の\nBMIは %f です\n", weight, height, weight/(height*height));

 return 0;
}
