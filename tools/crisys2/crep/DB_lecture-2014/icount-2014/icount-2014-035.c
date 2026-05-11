#include <stdio.h>


void figurecount(char src[]);
//グローバルな配列countに各数字の個数を返す
int count[10];

int main() {
  printf("文字列を入力しなさい : ");

  char str[256];
  fgets(str,256,stdin);
  printf("%sには\n",str);
  figurecount(str);
  int i=0;
  for(i=0;i<10;i++){
    printf("%d が %d 個\n",i,count[i]);
  }
  printf("含まれています。\n");
  return 0;
}

void figurecount(char src[]){
  int i,j;
  char figure[10][2]={ "0","1","2","3","4","5","6","7","8","9" };
  for(j=0;j<10;j++){
    for(i=0;i<256;i++){
      if (src[i]=='\0') {
	break;
      }
      if (src[i]==figure[j][0]) {
	count[j]+=1;
      }
    }
  }
  return;
}
