#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a,int b);
int (*p[5]) (int x, int y);

int main(void){
  int result, i, j, op;

  p[0] = sum; 
  p[1] = subtract; 
  p[2] = mul; 
  p[3] = div; 
  p[4] = power;

  printf("2つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0:加算、1:減算、2:乗算、3:除算、4:べき乗\n");

  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while ((op < 0) || (op > 4));

  result = (*p[op]) (i, j);
  printf("結果:%d\n",result);

  return 0;
}

int sum(int a,int b){
  int t;
  t=a+b;
  return t;
}

int subtract(int a,int b){
  int t;
  t=a-b;
  return t;
}

int mul(int a,int b){
  int t;
  t=a*b;
  return t;
}

int div(int a,int b){
  int t;
  t=a/b;
  return t;
}

int power(int a,int b){
  int i;
  int t=1;
  for(i=0;i<=b-1;i++){
    t = t*a ;
  }
  return t;
}
