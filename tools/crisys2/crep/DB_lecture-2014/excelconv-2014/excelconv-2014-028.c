#include<stdio.h>
#include<string.h>

int excelconv(char excel[6]);
int main(int argc, char *argv[])

{
  int m;
  m = excelconv(argv[1]);
  printf("%d" ,m );

  return 0;
}

int excelconv(char excel[6])

{
  int e,i,count,al,m,sum;
  e = 0;
  i = 0;
  count = strlen(excel);
  sum = 0;

  while(excel[i]){
    e = excel[i] - 64;
    al = 1;
    m = 0;

    while( m < count - i -1){
      al = 26 * al;
      m++;
    }
   
 sum = sum + e * al;
    i++;
  }
    return sum;
}
