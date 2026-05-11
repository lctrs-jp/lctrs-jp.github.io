#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[]){
  int i,k,c = 0,j; //iは繰り返しのための変数,cは各桁の数を一時的に保存
  k = 0;//kは合計を保存
  for(j = 0; *(argv[1] +  j) != '\0' ; j++);//jの値はmainの引数の文字の数
  if(argc != 2 ){
    printf("AからZZZZZまでを入力してください\n");
    printf("もう一度入力してください\n");
    exit(1);
  }
  for(i = 1;  *(argv[1] + i - 1) != '\0' ; i++){
    c = *(argv[1] + i - 1);
    c = c - 64;
    c = pow(26, j - i ) * c ;
    k = k + c;
  }
  printf("%d\n", k);
  return 0;
}
