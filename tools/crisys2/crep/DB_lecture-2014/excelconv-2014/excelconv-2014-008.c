#include<stdio.h>
#include<string.h>

int excel(char num[6]);

int main(int argc,char *argv[])
{
  int t;
  t = excel(argv[1]);
  printf("%d\n",t);

  return 0;
}

int excel( char num[6])
{
  int a,b,con,all,c,sum;
  a=0;
  b=0;
  con = strlen(num);
  sum =0;

  while(num[b]){
    a=num[b]-64;
    all=1;
    c=0;
    while(c < con-b-1){
      all=26*all;
      c++;
    }
    sum=sum+a*all;
    b++;
  }

  return sum;

}
