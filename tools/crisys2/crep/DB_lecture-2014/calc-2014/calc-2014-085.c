#include <stdio.h>

int sum(int a, int b); /* 和 */
int subtract(int a, int b); /* 差 */
int mul(int a, int b); /* 積 */
int div(int a, int b); /* 商 */
int modulus(int a, int b); /* 剰余 */
int power(int a, int b); /* べき乗 */

/* ポインタ配列の初期化 */
int (*p[6]) (int x, int y) = {
  sum, subtract, mul, div, modulus, power
};

int main(void)
{
  int result;
  int i, j, op;

  printf("2つの数字を入力してください\n");
  printf("1つめ:");
  scanf("%d", &i);
  printf("2つめ:");
  scanf("%d", &j);

  printf("0: 和, 1: 差, 2: 積, 3: 商, 4: 剰余, 5: べき乗\n");
  do{
    printf("演算の番号を入力してください:");
    scanf("%d", &op);
  }
  while((op < 0)||(op > 5));

  result = (*p[op]) (i, j);
  printf("Answer:%d\n", result);

  return 0;
}

int sum(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int mul(int a, int b)
{
  return a * b;
}

int div(int a, int b)
{
  if(b)
    return a / b;
  else
    return 0;
}

int modulus(int a, int b)
{
  if(b)
    return a % b;
  else
    return 0;
}

int power(int a, int b)
{
  int ans = 1, i;
  if(b){
    for(i = 0; i < b; i++)
      ans = ans * a;
    return ans;
  }
  else
    return 1;
}
