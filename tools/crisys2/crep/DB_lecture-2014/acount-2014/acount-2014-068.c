#include<stdio.h>

int main() {

  char item[255];
  char moji = 'a';
  int i,j,count,max;

  printf("文字列を入力してください:");
  scanf ("%s", &item);

  for(j = 0; j <= 25; j++) {
    count = 0;
    for(i = 0; item[i]; i++) {
      if(item[i] == moji)
        count++;
    }
    max=0;
    if(max < count) {
      max = count; }
  }
         
  printf("出現回数は%d回",max);
  moji++;
}

