#include <stdio.h>

int main(void)
{
  int i, num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0;
  int num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;
  char str[100];

  printf(" 数字列を入力してください(長さ100未満): ");
  gets(str);

  for (i = 0; str[i] !='\0'; i++){
    switch (str[i]) {
    case '0':
      num0++;
      break;
    case '1':
      num1++;
      break;
    case '2':
      num2++;
      break;
    case '3':
      num3++;
      break;
    case '4':
      num4++;
      break;
    case '5':
      num5++;
      break;
    case '6':
      num6++;
      break;
    case '7':
      num7++;
      break;
    case '8':
      num8++;
      break;
    case '9':
      num9++;
      break;
    }
  }

  printf("0は %d個含まれています \n", num0);
  printf("1は %d個含まれています \n", num1);
  printf("2は %d個含まれています \n", num2);
  printf("3は %d個含まれています \n", num3);
  printf("4は %d個含まれています \n", num4);
  printf("5は %d個含まれています \n", num5);
  printf("6は %d個含まれています \n", num6);
  printf("7は %d個含まれています \n", num7);
  printf("8は %d個含まれています \n", num8);
  printf("9は %d個含まれています \n", num9);

  return 0;
}
