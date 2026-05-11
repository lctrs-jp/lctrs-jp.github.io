#include <stdio.h>
#include <string.h>

int main(void)
{
  int a,t,n;
  printf("2以上の整数を入力してください\n");
  scanf("%d",&a); 

  while( a != 1 ){
    if(a % 2 == 0){
    t = a / 2;
    a = t;
    printf("%d\n",a);

}
    else { 
    t = (a * 3) + 1;
    a = t;
    printf("%d\n",a);

}
  }

  printf("%d\n",a);
  
  return 0;
}
