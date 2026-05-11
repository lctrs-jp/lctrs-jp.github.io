#include<stdio.h>


int sum(int a, int b);
int modulus(int a, int b);
int power(int a, int b);

int (*p[3])(int x, int y);


int main(void){
  int result, i, j, op;

  p[0] = sum;
  p[1] = modulus;
  p[2] = power;

  printf("二つの数字を入力して下さい:");
  scanf("%d%d", &i, &j);
  printf("0: 加算, 1:余り, 2:累乗\n");
  do{
    printf("演算の番号を入力して下さい: ");
    scanf("%d", &op);
  }while ((op < 0) || (op > 2));
  result = (*p[op]) (i, j);
  printf("%d", result);

  return 0;
}



int sum(int a, int b)
{
  return a + b;
}

int modulus(int a, int b)
{
  return a % b;
}

int power(int a, int b)
{
  if(b != 0){
    return a * power(a, b-1);
  }
  else{
    return 1;
  }
}
  
