#include <stdio.h>
#include <string.h>

//#define DEBUG
#define MAX 5		// 解釈する文字列の最大桁数
#define BASE 26		// n進数. n = ?
#define GAP 64		// int('A')と1の差
#define SIZE 256

int excelconv(const char* str);
int pow_i(int n, int m);		// n^m
void test(void); 

int main(int argc, char* argv[])
{
  int res;

#ifdef DEBUG
  printf("test excelconv()\n");
  test();
#else
  if(argc == 2){
    res = excelconv(argv[1]);
    if(res == 0)
      printf("argument error.\n");
    else
      printf("%d\n", res);
  }else{
    printf("Usage: ./excelconv [capital string]\n");
  }
#endif

  return 0;
}

int excelconv(const char* str)
{
  int i;
  int c;
  int len;

  // assertion check
  len = strlen(str);
  if(len > MAX)
    return 0;

  // calculation
  c = 0;
  for(i=0; i<len; i++)
    if('A' <= str[i] && str[i] <= 'Z')
      c += (str[i] - GAP) * pow_i(BASE, len-i-1);
    else
      return 0;
  return c;
}

int pow_i(int n, int m)
{
  if(m == 0)
    return 1;
  else
    return n * pow_i(n,m-1);
}

void test(void)
{
  int i;
  char str[5][SIZE] = { "A", "%", "AA", "XFD", "AAAAAA" };

  for(i=0; i<5; i++)
    printf("%6s :\t%d\n", str[i], excelconv(str[i]));

  return;
}
