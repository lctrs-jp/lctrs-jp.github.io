#include <stdio.h>

int sum1(int n)
{
  int i = 0;
  int res = 0;

  if(n < 0)return res;

  for(i = 0; i <= n; i++)
  {
    res += i;
  }

  return res;
}

int sum2(int n);

main()
{
  int result = 0;
  int input = 0;

  printf("Input natural number.>>");
  scanf("%d", &input);
  printf("\n");

  result = sum1(input);

  while(result == 0)
  {
    printf("Input NATURAL NUMBER.>>");
    scanf("%d", &input);
    printf("\n");
    result = sum1(input);
  }
  printf("sum1(%d) = %d\n", input, result);

  result = sum2(input);

  while(result == 0)
  {
    printf("Input NATURAL NUMBER.>>");
    scanf("%d", &input);
    printf("\n");
    result = sum2(input);
  }
  printf("sum2(%d) = %d\n", input, result);

  return;
}

int sum2(int n)
{
  if(n <= 0) return 0;
  else return (n + sum2(n - 1));
}
