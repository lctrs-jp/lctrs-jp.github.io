#include <stdio.h>

int main(void)
{
  int a;

  printf("数字を入力してください。\n");
  scanf("%d",&a);

  for(;;){
    if(a==1){
      break;
    }
   else if(a%2==1){
      a=(a*3)+1;
      printf("%d\n",a);
    }
    else if(a%2==0){
      a=a/2;
      printf("%d\n",a);
    }
  }
  return 0;
}
