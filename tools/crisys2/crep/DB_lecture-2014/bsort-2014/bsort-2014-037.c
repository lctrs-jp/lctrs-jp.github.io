#include <stdio.h>

void printitem(int trg[],int cnt);

int main() {
  int item[100],a,b,t,count;
  
  printf ("数をいくつ入力しますか?");
  scanf("%d",&count);
  for (a=0;a<count;a++){
    scanf("%d",&item[a]);
  }
  for (a=1;a<count;++a) {
    for (b=count-1;b>=a;--b) {
      if (item[b-1]>item[b]) {
        t=item[b-1];
        item[b-1]=item[b];
        item[b]=t;
	printitem(item,count);
      }
    }
  }
  for(t=0;t<count;t++) {
    printf("%d",item[t]);
  }

  return 0 ;
}


void printitem(int trg[],int cnt) {
  //文字列itemを表示するだけの関数
  int i;
  for(i=0;i<cnt;i++){
    printf("%d ",trg[i]);
  }
  printf("\n");
  return;
}


