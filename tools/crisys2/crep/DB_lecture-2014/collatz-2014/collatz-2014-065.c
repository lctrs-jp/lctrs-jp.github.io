#include<stdio.h>
int make1(int n)
{
  int num;
  while(n >= 2 && n<3*2^53)
    {
      num=0;
      while (n>1) {
	if (num%2=0){num = n/2;}
	else{n = n*3+1;}
      }
      n = num;
    }
  return n;
}
printf(入力,%s);
scanf(%s\n);
return 0;
