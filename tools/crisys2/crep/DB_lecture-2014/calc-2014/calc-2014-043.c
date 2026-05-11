#include <stdio.h>
#include <math.h>

int sum(int a, int b);//+
int subtract(int a, int b);//-
int mul(int a, int b);//*
int div(int a, int b);///
int modulus(int a, int b);//%
int power(int a, int b);//^

int (*p[6])(int x, int y) = {sum, subtract, mul, div, modulus, power};

int main(){
  int result;
  int i, j, op;
  
  printf("２つの数を入力してください。\n");
  scanf("%d%d", &i, &j);
  printf("0:加算、1:減算、2:乗算、3:除算、4:余り、5:累乗\n");
  do{
    printf("演算番号を入力してください。\n");
    scanf("%d", &op);
  }while(op < 0 || op > 5);
  result = (*p[op])(i, j);
  printf("%d\n", result);
  return 0;
}

int sum(int a, int b){return (a + b);}
int subtract(int a, int b){return (a - b);}
int mul(int a, int b){return (a * b);}
int div(int a, int b){return (a / b);}
int modulus(int a, int b){return (a % b);}
int power(int a, int b){return (int)pow(a, b);}
