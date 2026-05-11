#include <stdio.h>

int main(void)
{
  int i, count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
  char str[100];

  printf("数字列を入力してください(長さ100以下):");
  gets(str);

  for (i = 0; str[i] != '\0'; i++){
    switch (str[i]){
    case '0':
      count0++;
      break;
    case '1':
      count1++;
      break;
    case '2':
      count2++;
      break;
    case '3':
      count3++;
      break;
    case '4':
      count4++;
      break;
    case '5':
      count5++;
      break;
    case '6':
      count6++;
      break;
    case '7':
      count7++;
      break;
    case '8':
      count8++;
      break;
    case '9':
      count9++;
      break;
    }
  }

  printf("0は%d個含まれています。\n", count0);
  printf("1は%d個含まれています。\n", count1);
  printf("2は%d個含まれています。\n", count2);
  printf("3は%d個含まれています。\n", count3);
  printf("4は%d個含まれています。\n", count4);
  printf("5は%d個含まれています。\n", count5);
  printf("6は%d個含まれています。\n", count6);
  printf("7は%d個含まれています。\n", count7);
  printf("8は%d個含まれています。\n", count8);
  printf("9は%d個含まれています。\n", count9);

  return 0;
}
