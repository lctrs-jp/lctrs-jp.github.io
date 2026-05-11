#include <stdio.h> /*課題10*/
int sum(int a, int b);
int substract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a,int b);
int power(int a, int b);

/* ポインタ配列を初期化 */
int (*p[6]) (int x, int y) = {
  sum, substract, mul, div, modulus, power
};

     int main(void){
       int result, i, j, op;

       printf("２つの数字を入力してください:");
       scanf("%d%d", &i, &j);
       printf("0: 加算, 1: 減算, 2: 乗算, 3: 除算, 4: 剰余算, 5: べき乗\n");
       do{
         printf("演算の番号を入力してください: ");
         scanf("%d", &op);
       }while((op < 0) && (op > 5));
       result = (*p[op]) (i, j);
       printf("%d\n", result);

       return 0;
     }

     int sum(int a, int b)
  {
    return a + b;
  }
     int substract(int a, int b)
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
int modulus(int a, int b){
  if(b)
    return a % b;
 else
   return 0;
}
int power(int a, int b){
  int n, q;
  q = 1;
 for(n = 1; n <= b; ++n)
   q = q * a;
 return q;
}
