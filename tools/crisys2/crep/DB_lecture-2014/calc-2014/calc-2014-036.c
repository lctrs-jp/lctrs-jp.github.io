#include <stdio.h>

int sum(int a,int b);
int substract(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int modulus(int a,int b);
int power(int a,int b);

/*ポインタを初期化する*/
int(*p[6])(int x,int y)={sum,substract,mul,div,modulus,power};

int main(void){
  int result;
  int i,j,op;

  printf("数字を入力してください。:");
  scanf("%d",&i);
  printf("もう一つ数字を入力してください。:");
  scanf("%d",&j);

  printf("1.加算\n");
  printf("2.減算\n");
  printf("3.乗算\n");
  printf("4.除算\n");
  printf("5.剰余\n");
  printf("6.べき乗\n");
  do{
    printf("演算の番号を入力してください。:");
    scanf("%d",&op);
    op=op-1;
  }while((op<0)||(op>5));

  result=(*p[op])(i,j);
  printf("%d\n",result);

  return 0;
}

int sum(int a,int b){
  return a+b;
}

int substract(int a,int b){
  return a-b;
}

int mul(int a,int b){
  return a*b;
}

int div(int a,int b){
  if(b!=0)
    return (a/b);
  else
    return 0;
}

int modulus(int a,int b){
  if(b!=0)
    return(a%b);
  else
    return 0;
}

int power(int a,int b){
  if(b>1){
  return (power(a,b-1)*a);
  }
  else if(b<0) return 0;
}
