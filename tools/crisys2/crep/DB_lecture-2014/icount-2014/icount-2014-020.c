#include <stdio.h>

main()
{
  char str[100];
  int i,j;

  printf("数字列を入力してください(長さ100以下) : ");
  scanf("%s", str);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '0') {
      j++ ;
    }
  }
    printf("0は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '1') {
      j++ ;
    }
  }
    printf("1は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '2') {
      j++ ;
    }
  }
    printf("2は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '3') {
      j++ ;
    }
  }
    printf("3は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '4') {
      j++ ;
    }
  }
    printf("4は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '5') {
      j++ ;
    }
  }
    printf("5は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '6') {
      j++ ;
    }
  }
    printf("6は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '7') {
      j++ ;
    }
  }
    printf("7は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '8') {
      j++ ;
    }
  }
    printf("8は%d個含まれています。\n", j);

  j = 0;
  for ( i = 0; str[i] ; i++) {
    if (str[i] == '9') {
      j++ ;
    }
  }
    printf("9は%d個含まれています。\n", j);

  return 0;
}
