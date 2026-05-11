#include<stdio.h>

void downcase(char str[]);

int main(void){
  
  char name[20];
  printf("文字列を入力:");
  fgets(name,20,stdin);
  
  downcase(name);
  printf(name);
  
  return 0;
}
void downcase(char str[]){
  int i;
  for(i = 0;str[i];i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] = str[i] - 'A' + 'a';
    }
  }
  return;
}
