#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])  
{
  int x, z, n, i, len;

  n = 0;
  for(len = 0; *(argv[1] + len) != '\0'; len++); //打ち込んだ文字の長さを数える

  for(i = 0; *(argv[1] + i) != '\0' ; i++){        //終端まで繰り返す
    x = *(argv[1] + i) - 64;              //その桁の文字を数字にして取り出す
    z = x * (int)pow(26,(len - i - 1));   //26進数の計算①
    n = n + z;                            //26進数の計算②
    }

  printf("%d\n", n);

  return 0;
}
