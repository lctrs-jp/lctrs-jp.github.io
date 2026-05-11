#include <stdio.h>

int main()
{
  char str[101];
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, n; 
  int count = 0;

  printf("文字列を入力してください（長さ100以下）: ");
  gets(str);

  while(str[count] != '\0')
    count++;

  for(n = 0; n < count; n++){
    switch (str[n]){
      case '0':
        a++;
	break;
      case '1':
        b++;
	break;
      case '2':
	c++;
	break;
      case '3':
	d++;
	break;
      case '4':
        e++;
	break;
      case '5':
	f++;
	break;
      case '6':
	g++;
	break;
      case '7':
	h++;
	break;
      case '8':
	i++;
	break;
      case '9':
	j++;
	break;
    }
  }

  printf("0は%d個含まれています.\n1は%d個含まれています.\n2は%d個含まれています.\n3は%d個含まれています.\n4は%d個含まれています.\n5は%d個含まれています.\n6は%d個含まれています.\n7は%d個含まれています.\n8は%d個含まれています.\n9は%d個含まれています.\n", a, b, c, d, e, f, g, h, i, j);

    return 0;
}
