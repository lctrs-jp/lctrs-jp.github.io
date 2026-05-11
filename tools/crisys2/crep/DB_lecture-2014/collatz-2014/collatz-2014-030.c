#include <stdio.h>

int is_odd(int n);

int main()
{
  int t;

  printf("２以上の整数を入力してください: ");
  scanf("%d", &t);
  printf("%d", t);

  while(t != 1){
    if(is_odd(t) == 0){
      t = t / 2;
      printf("-> %d", t);
    }
    if(is_odd(t) == 1){
      t = 3 * t + 1;
      printf("-> %d", t);
    }
  }

  return 0;
}

int is_odd(int n)
/* n が 奇数なら真(0以外)，偶数なら偽(0) を返す関数*/
{
  int t;
  
  if(n % 2 == 0)
    t = 0;
  else
    t = 1;
  
  return t;
}
