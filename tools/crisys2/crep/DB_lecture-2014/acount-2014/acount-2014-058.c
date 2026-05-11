#include<stdio.h>
#include<string.h>

int main() 
{
  int i, j, k, a[10],n;
  char str[100];
  
  i = 0;
  j = 0;
  k = 0;
  printf("文字列を入力してください: ");
  fgets(str, 100, stdin);
  for (i = 0; i < 100; i++){
    a[i] = 0;
  }
  for(j = 0 ; j < 100; j++){
    for(i = 0; str[i] != '\0'; i++){
      if (str[i] == j + 17 ){
	a[j]++;
      }
    }
    for(k = 0; str[i] = '\0'; k++){
      if (str[i] == j + 49){
	a[j]++;
      }
    }
  }
  
  
  printf("最頻出文字 %s は %d 回出現した。\n", str[j]);
 return 0;
}
