#include <stdio.h>

int main(void)
{
  char str[101];
  //strは数字列
  int i,j, k[10];
  for(i = 0; i <= 10; i++)
    k[i] = 0;
  //iは数字列の数ぶん繰り返すための変数
  //kは数字jがstrに含まれている数を記録
  printf("数字列を入力してください(長さ１００以下)  :");
  scanf("%s", str);
  for(i = 0; str[i] != '\0'; i++){
    if(str[i] == '0'){
      k[0] = k[0] + 1;
    }
    if(str[i] == '1'){
      k[1] = k[1] + 1;
    }
    if(str[i] == '2'){
      k[2] = k[2] + 1;
    }
    if(str[i] == '3'){
      k[3] = k[3] + 1;
    }
    if(str[i] == '4'){
      k[4] = k[4] + 1;
    }
    if(str[i] == '5'){
      k[5] = k[5] + 1;
    }
    if(str[i] == '6'){
      k[6] = k[6] + 1;
    }
    if(str[i] == '7'){
      k[7] = k[7] + 1;
    }
    if(str[i] == '8'){
      k[8] = k[8] + 1;
    }
    if(str[i] == '9'){
      k[9] = k[9] + 1;
    }
    
  }

  for(j = 0; j < 10; j++){
    printf("%d は %d個含まれています\n", j, k[j]);
  }
	

  return 0;
}
