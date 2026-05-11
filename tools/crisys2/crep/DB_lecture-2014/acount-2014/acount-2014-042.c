#include<stdio.h>

int main(void){
  char str[100],l;
  int i,m[57],n,k,s,t;

  for ( n = 0; n < 58; n++){
    m[n] = 0;
  }

  printf("文字列を入力してください(１００文字以下):");
  fgets( str, 100, stdin);
  for ( i = 0; str[i] != '\0'; i++){
    if(str[i] == 65){
      m[0] = m[0] + 1;
    }
  for ( k = 1; k <= 57; k++){
    if ( str[i] == k + 65){
      m[k] = m[k] + 1;
    }
  }
  }

  for ( l = 65; l < 123; l++){

      k = l -65;
      printf("%cは%d個含まれています。", l,m[k]);
      
  }
  1 <= s <= 25;
  1 <= t <= 25; 
  for (s = 0; m[s]+m[s+32] < m[t]+m[t+32]; s++){

    printf("%d個がさいだいです",m[t]);
      }
  return 0;
}
 
