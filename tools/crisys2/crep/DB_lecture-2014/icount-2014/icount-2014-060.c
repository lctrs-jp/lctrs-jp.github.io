#include <stdio.h>

int main(void)
{
  int i;
  int zero = 0;
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
  int five = 0;
  int six = 0;
  int seven = 0;
  int eight = 0;
  int nine = 0;

  char num[101];

  printf("数字列を入力してください(長さ100以下): ");
  fgets(num, 100, stdin);

  for(i = 0; num[i + 1] != '\0'; i++) {
	if(num[i] == 48)
	  zero = zero + 1;
	else if(num[i] == 49)
	  one = one + 1;
	else if(num[i] == 50)
	  two = two + 1;
	else if(num[i] == 51)
	  three = three + 1;
	else if(num[i] == 52)
	  four = four + 1;
	else if(num[i] == 53)
	  five = five + 1;
	else if(num[i] == 54)
	  six = six + 1;
	else if(num[i] == 55)
	  seven = seven + 1;
	else if(num[i] == 56)
	  eight = eight + 1;
	else if(num[i] == 57)
	  nine = nine + 1;
  }

  printf("0 は %d個含まれています\n", zero );
  printf("1 は %d個含まれています\n", one );
  printf("2 は %d個含まれています\n", two );
  printf("3 は %d個含まれています\n", three );
  printf("4 は %d個含まれています\n", four );
  printf("5 は %d個含まれています\n", five );
  printf("6 は %d個含まれています\n", six );
  printf("7 は %d個含まれています\n", seven );
  printf("8 は %d個含まれています\n", eight );
  printf("9 は %d個含まれています\n", nine );

  return 0;
}
