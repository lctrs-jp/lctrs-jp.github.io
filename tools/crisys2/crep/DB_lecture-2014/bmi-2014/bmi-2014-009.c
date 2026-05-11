#include <stdio.h>
int main(void)
{
  float x,y,z;/*x=身長, y=体重, z=身長の二乗*/
  printf("あなたの身長は(cm):");
  scanf("%f", &x);
  printf("あなたの体重は(㎏):");
  scanf("%f", &y);

  z=x*x/10000;

  printf("あなたのBMIは%f\n", y/z);

  return 0;
}
