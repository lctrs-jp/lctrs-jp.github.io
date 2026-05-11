#include<stdio.h>

int main()
{
  long int i;
  printf("2以上の数字をにゅうりょくしてください:");
  scanf("%ld",&i);
  printf("%ld",i);
  for(;i!=1;)
    if(i%2){
      i=i*3+1;
      printf("->%ld",i);
    }
    else{
      i=i/2;
      printf("->%ld",i);
    }
  printf("\n");
  return 0;
}
