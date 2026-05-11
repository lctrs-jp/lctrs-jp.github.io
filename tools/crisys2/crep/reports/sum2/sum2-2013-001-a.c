#include <stdio.h>

int hikaku(int x,int y);
int max(int x, int y);
int min(int x, int y);
int sum2(int x, int y);

int main(void)
{
  int atai1, atai2, sum;
  sum = 0;

  while(1){
    printf("Input two different integers\n1st one: ");
    scanf("%d", &atai1);
    printf("2nd one: ");
    scanf("%d", &atai2);

    if(hikaku(atai1, atai2)) break;
    else printf("Those are the same. Please input again.\n");
  }
  
  if (atai1 <= atai2)
    printf("summation from %d to %d is %d.\n", atai1, atai2, sum2(atai1, atai2));
  else printf("summation from %d to %d is %d.\n", atai2, atai1, sum2(atai2, atai1));

  return 0;
}

int hikaku(int x, int y)
{
  if(x > y) return 1;
  else if(x < y) return -1;
  else return 0;
}

int max(int x, int y)
{
  if(x > y) return x;
  else return y;
}

int min(int x, int y)
{
  if(y > x) return x;
  else return y;
}

int sum2(int x, int y)
{
  int t=0, i;
  if (x > y) return 0;

  for( i=min(x, y) ; i <= max(x, y) ; i++){
    t += i;
  }

  return t;
}
