#include <stdio.h>

int main(void)
{
  int item[100];
  int a,b,t;
  int count;

  printf("how many numbers do you input?\n");
  scanf("%d",&count);
  printf("input %d numbers\n",count);
  for(a=0;a<count;a++)
    scanf("%d",&item[a]);
	printf("\n");

  //sort//
  for(a=1;a<count;++a)
    for(b=count-1;b>=a;--b){
      //compare//
      if (item[b-1]>item[b]){
	//switch//
	t=item[b-1];
	item[b-1]=item[b];
	item[b]=t;

	for(t=0;t<count;t++)   
	  printf("%d ",item[t]);
	printf("\n");

      }
    }

  //output the list//

  printf("\n");
  for(t=0;t<count;t++)
    printf("%d ",item[t]);

  return 0;
}
