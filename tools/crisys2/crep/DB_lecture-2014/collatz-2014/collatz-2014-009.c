#include <stdio.h>

int main()
{

  int m, n;
  printf("２以上の数値を入力してください:");
  scanf("%d", &m);

  while (m > 2){

    if (m%2==0){
      m=m/2;
    }
     else {
       m=3*m+1;
     }
    printf("%d->",m);
  }
  printf("1\n");

  return 0;
}
