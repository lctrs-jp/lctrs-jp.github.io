#include<stdio.h>

int sum2(int i);

int sum1(int i)
{
  int n,m;
  m = 0;

  if(i<=0){ 

    return 0;

  }else{
    for(n=1;n<=i;n++){
      m = n + m;
    }

    return m;
  }
}

main()
{
  int a,b,c;

  printf("Input a natural number:");
  scanf("%d",&a);

  b = sum1(a);
  c = sum2(a);

  printf("result by sum1:%d\n",b);
  printf("result by sum2:%d\n",c);
 if(b==0){
  printf("Input a natural number\n");
 }
}

int sum2(int i)
{  
  if(i<=0){
    return 0;
  }else if(i==1){
    return 1;
  }else{
    return ( i + sum2(i-1));
  }
}
