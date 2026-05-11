#include<stdio.h>

int main() {
 
  char item[255];
  char num = '0';
  int i,j,count;

  printf("文字列を入力してください:");
  scanf ("%s", &item);

  for(j = 0; j <= 9; j++) {
    count = 0;
    for(i = 0; item[i]; i++) {
      if(item[i] == num)
	count++;
    }  
    printf("%dは%d個含まれている。\n",j, count);
    
   num++ ;
  }
  return 0;
}
