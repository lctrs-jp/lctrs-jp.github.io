#include <stdio.h>

int main()
{
  int item[100];
  int a,b,t;
  int count;

  printf("数をいくつ入力しますか？\n");
  scanf("%d",&count);

  printf("数字を入力してください。\n");
  for(a=0;a<count;a++)
    scanf("%d",&item[a]);

  printf("\n");

  for(a=0;a<count;a++)
  printf("%d",item[a]);

  printf("\n");

  for(a=1;a<count;++a)
    for(b=count-1;b>=a;--b){
      if(item[b-1]>item[b]){
	t=item[b-1];
	item[b-1]=item[b];
	item[b]=t;
	for(t=0;t<count;t++){
	  printf("%d",item[t]);
	}
	printf("\n");
      }
    }

  for(t=0;t<count;t++){
	printf("%d",item[t]);
  }
  printf("\n");

      return 0;
}
