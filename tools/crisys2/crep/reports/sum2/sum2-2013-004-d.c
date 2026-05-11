#include<stdio.h>

int sum(int m, int n){
  int s=0, i=m;
  if(m > n){
    return 0;
  }else{
    while(i <= n){
      s = s + i;
      i++;
   }
    return s;
  }
}

int main(){
  int m, n, s;

  printf("Input 1st Integer: ");
  scanf("%d", &m);
  printf("Input 2nd Integer: ");
  scanf("%d", &n);

  s  = sum(m, n);
  if(!s){
    s = sum(n, m);
  }
  printf("Sum = %d\n", s);

  return 0;
}
