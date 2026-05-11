#include<stdio.h>
int main(void)
{
  int item[100];
  int a , b,t,k;
  int count;

  printf("数をいくつ入力しますか？");
  scanf("%d",&count);
  for(a = 0;a < count; a++)
    scanf("%d",&item[a]);

  for(a = 1;a<count;++a){
    for(b= count-1 ; b >= a ; --b){

      if(item[b-1] > item[b]){
	t = item[b - 1];
	item[b - 1]= item[b];
	item[b] = t;    
      }
      for(k=0;k<count;k++){
	printf("%d",item[k]);
	if(k==count-1)
	  printf("\n");
      }}}

  return 0;
}

