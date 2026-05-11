#include <stdio.h>

int main(void)
{
  int i, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
  char str[100];

  c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;

 printf(" １００以下の数字を入力して下さい:  ");
 fgets(str, 100, stdin );

 for (i = 0; str[i] != '\0'; i++){
   switch (str[i]) {
   case '0':
   c0++;
   break;
   case '1':
   c1++;
   break;
   case '2':
   c2++;
   break;
   case '3':
   c3++;
   break;
   case '4':
   c4++;
   break;
   case '5':
   c5++;
   break;
   case '6':
   c6++;
   break;
   case '7':
   c7++;
   break;
   case '8':
   c8++;
   break;
   case '9':
   c9++;
   break;
   }}

 printf(" 0 は %d個含まれています. \n",c0);
 printf(" 1 は %d個含まれています. \n",c1);
 printf(" 2 は %d個含まれています. \n",c2);
 printf(" 3 は %d個含まれています. \n",c3);
 printf(" 4 は %d個含まれています. \n",c4);
 printf(" 5 は %d個含まれています. \n",c5);
 printf(" 6 は %d個含まれています. \n",c6);
 printf(" 7 は %d個含まれています. \n",c7);
 printf(" 8 は %d個含まれています. \n",c8);
 printf(" 9 は %d個含まれています. \n",c9);

 return 0;
}
