#include<stdio.h>
#include<string.h>
#include<math.h>

int recursion(char n[]);
int main(void) 
{
  char str[6];
  printf("大文字でアルファベットを入力してください\n");
  gets(str);
  printf("%d\n",recursion(str));
  return 0;

}

int recursion(char n[])
{
  int strl;
  long int x;
  
  strl=strlen(n);
  
  if(*n!='\0')
    {
    x=pow(26,strl-1)*(n[0]-64);
    n++;
    return x+recursion(n);
    }
}
