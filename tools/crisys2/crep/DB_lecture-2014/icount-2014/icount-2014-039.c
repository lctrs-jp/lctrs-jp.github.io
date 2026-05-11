#include <stdio.h>

int main()
{
  int p, q, r, abc0=0, abc1=0, abc2=0, abc3=0, abc4=0, abc5=0, abc6=0, abc7=0, abc8=0, abc9=0;
  char str[100];

  printf("数字列を入力してください(長さ100以下):");
  gets(str);

  for ( p = 0; str[p] !='\0'; p++){
    switch (str[p]) {
    case'0' :
      abc0 = abc0+1;
      break;
    case'1' :
      abc1 = abc1+1;
      break;
    case'2' :
      abc2 = abc2+1;
      break;
    case'3' :
      abc3 = abc3+1;
      break;
    case'4' :
      abc4 = abc4+1;
      break;
    case'5' :
      abc5 = abc5+1;
      break;
    case'6' :
      abc6 = abc6+1;
      break;
    case'7' :
      abc7 = abc7+1;
      break;
    case'8' :
      abc8 = abc8+1;
      break;
    case '9':
      abc9 = abc9+1;
      break;
    
    }
  }

  
  printf("0 は %d個含まれています。\n", abc0);
  printf("1 は %d個含まれています。\n", abc1);
  printf("2 は %d個含まれています。\n", abc2);
  printf("3 は %d個含まれています。\n", abc3);
  printf("4 は %d個含まれています。\n", abc4);
  printf("5 は %d個含まれています。\n", abc5);
  printf("6 は %d個含まれています。\n", abc6);
  printf("7 は %d個含まれています。\n", abc7);
  printf("8 は %d個含まれています。\n", abc8);
  printf("9 は %d個含まれています。\n", abc9);
  

  return 0;
} 
         
