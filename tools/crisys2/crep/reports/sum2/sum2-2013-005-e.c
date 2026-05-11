#include <stdio.h>
int sum2(int m, int n);

int main()
{
  int num1, num2, result;
  printf("Enter two numbers\n>>");
   scanf("%d", &num1);
   printf("\n>>");
   scanf("%d", &num2);
   
   result = sum2(num1, num2);
   if (result == 0)
     printf("ERROR\n");
   else
     printf("Result = %d\n",result); 
   return 0;
}

int sum2(int m, int n)
{
  int count = 0;
  while (m <= n)
    {
      count = count + m;
      m++;
    }
  return count;
}
