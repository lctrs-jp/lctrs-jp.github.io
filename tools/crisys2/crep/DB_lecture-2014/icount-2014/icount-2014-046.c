#include <stdio.h>

int main()
{
  int i, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, j = 0, k= 0;
  char str[100];  


  printf("数字列を入力してください（長さ１００以下）");
  gets(str);
  for(i = 0; str[i] != '\0'; i++){
    if (str[i] == '0')
      a++;
    
    else if (str[i] == '1')
      b++;

    else if (str[i] == '2')
      c++;

    else if (str[i] == '3')
      d++;

    else if (str[i] == '4')
      e++;

    else if (str[i] == '5')
      f++;

    else if (str[i] == '6')
      g++;

    else if (str[i] == '7')
      h++;

    else if (str[i] == '8')
      j++;

    else 
      k++;
  }

  printf("0 は　%d　個含まれています。\n", a);
  printf("1 は　%d　個含まれています。\n", b);
  printf("2 は　%d　個含まれています。\n", c);
  printf("3 は　%d  個含まれています。\n", d);
  printf("4 は　%d　個含まれています。\n", e);
  printf("5 は　%d　個含まれています。\n", f);
  printf("6 は　%d　個含まれています。\n", g);
  printf("7 は　%d  個含まれています。\n", h);
  printf("8 は　%d　個含まれています。\n", j);
  printf("9 は　%d  個含まれています。\n", k);
  
  return 0;
}
