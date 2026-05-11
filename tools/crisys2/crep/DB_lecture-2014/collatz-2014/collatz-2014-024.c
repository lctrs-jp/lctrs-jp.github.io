#include<stdio.h>

int main()
{
  int n;

  printf("数字を入力してください:");
  scanf("%d",&n);
  
  for(;;){
    printf("%d\n",n);
    if(n%2==0){
      n=n/2;
      if(n==1)
	break;
    }
    else 
      n=(n*3)+1;

     
  }
  printf("%d\n",n);

  return 0;
}
