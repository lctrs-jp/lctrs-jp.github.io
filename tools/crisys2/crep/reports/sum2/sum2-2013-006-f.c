#include <stdio.h>

int sum2(int a, int b);

int main(void)
{
  int x, y;

  printf("Input two numbers:");
  scanf("%d", &x);
  scanf("%d", &y);

  if(x == y)
    printf("Error:same numbers.\n");
  else if(x < y)
    printf("Summation is %d.\n", sum2(x, y));
  else
    printf("Summation is %d.\n", sum2(y, x));

  return 0;
}

int sum2(int a, int b)
{
  int c = 0;

  if(a < b)
    while(b >= a){
      c = c + b;
      b = b--;
    }

  return c;
}
