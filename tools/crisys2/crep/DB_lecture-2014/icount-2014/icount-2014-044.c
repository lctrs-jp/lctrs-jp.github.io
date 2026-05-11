#include<stdio.h>
#include<string.h>

int main() 
{
  int i, j, a[10];
  char str[100];
  
  printf("文字列を入力してください: ");
  fgets(str, 100, stdin);
  for (i = 0; i < 10; i++){
    a[i] = 0;
  }
  for(j = 0; j < 10; j++){
    for(i = 0; str[i] != '\0'; i++){
      if (str[i] == j + 48 ){
	a[j]++;
      }
    }
      printf("%d は %d 個含まれています\n", j, a[j] );
   }  
  return 0;
}
