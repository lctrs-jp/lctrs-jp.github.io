#include<stdio.h>

int sum1(int n){	      	
  int p;

  if(n<=0){
    p = 0;	                
  }else{			
   for(p=0; n>=1; n--){		
    p = p + n;
   }
  }
 
  return p;			
}

main(){
  int m;

  printf("Input a natural number: ");
  scanf("%d",&m);

  if(sum1(m)<=0){			
    printf("Input is illeagal\n");

  }else{
   printf("summation to %d by sum1:%d\n", m, sum1(m));	
   printf("summation to %d by sum2:%d\n", m, sum2(m));	
  }

}

int sum2(int n){		
  int p;

  if(n<=0){			
    p = 0;

  }else{			
    p = n + sum2(n-1);		
  }

  return p; 			
}
