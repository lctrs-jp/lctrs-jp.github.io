#include <stdio.h>

void test();
void calcNum(int n);

int main(void)
{
  // test calcNum()
  test();

  return 0;
}

void test()
{
  int input;

  printf("input a number bigger than two: ");
  scanf("%d", &input);

  calcNum(input);

  return;
}

void calcNum(int n)
{
  // assertion check
  if(n <= 2){
    printf("number error\n");
    return;
  }

  printf("%d", n);
  while(n != 1){
    if(n % 2)
      n = n*3 + 1;
    else
      n /= 2;
    printf(" => %d", n);
  }
  printf("\n");

  return;
}
