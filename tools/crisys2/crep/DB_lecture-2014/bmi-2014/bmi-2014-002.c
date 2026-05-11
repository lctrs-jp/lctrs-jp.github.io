#include <stdio.h>
int main()
{
  float h,w,b; 
  printf("身長（m）は？");
  scanf("%f" , &h);   /* 身長を入力 */
    printf("体重（kg）は？");
  scanf("%f" , &w);   /* 体重を入力 */
  b=w/(h*h);   /* BMIを計算 */
  printf("BMI=%f\n",b); /* BMIを表示*/
    return 0;
}
