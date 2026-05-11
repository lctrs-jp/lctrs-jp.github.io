#include<stdio.h>
#include<string.h>
#include<math.h>
void ex(char *al);
int main (int argc, char *argv[])
{
  printf("excelconv %s ",argv[1]);
  ex(argv[1]);
  return 0;
}

void ex(char *al){
  int x,y,z,p;
  p=strlen(al);
  z=0;
  for(x=p-1;x>=0;x--){
    y=pow(26,p-x-1);
    z=y*(*(al+x)-'A'+1)+z;}
  printf("→%d\n",z);
   }
