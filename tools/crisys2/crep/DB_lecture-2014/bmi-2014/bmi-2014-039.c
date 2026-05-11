#include <stdio.h>

int main()
{
  int weight;
  float height;

  printf("weight:");
  scanf("%d", &weight);
  printf("height:");
  scanf("%f", &height);

  printf("bmi= %f", weight/(height*height));

  return 0;
}
