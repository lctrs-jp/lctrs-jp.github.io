#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, sum;/*sumは１０進数に変換した値を収納する*/
  
    sum = 0; 
    for(i = 0; *(argv[1]+i) != '\0' && *(argv[1]+i) <= 'Z' && *(argv[1]+i) >= 'A' ; i++){/*A～Zを1文字ずつ上位桁から変換*/
      if(i >= 5){
	printf("エラー\n");
	break;/*５文字より多いならエラーを表示し、ループ終了*/
      }
      sum = sum*26 + *(argv[1]+i) - 64;/*すでに変換したものに26をかけ、新たに変換した桁を足す*/
    }
    printf("%d\n",sum);
  
  return 0;
}
