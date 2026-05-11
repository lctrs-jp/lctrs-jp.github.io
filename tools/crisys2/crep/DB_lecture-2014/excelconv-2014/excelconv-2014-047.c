
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a,i,b,d,e,f,g;
  char c,s[6];
  a=0;
  f=0;
  while(argv[1][f]!='\0'){
    s[f]=argv[1][f];
    f++;
  }
  g=0;
  while(f>0){
    argv[1][f-1]=s[g];
    f--;
    g++;
  }
  for(i=0;argv[1][i]!='\0';i++){
    c=argv[1][i];
    printf("%c\n", argv[1][i]);
    b=c-64;
    d=1;
    e=0;
    while(e!=i){    
      d=(d*26);
      e++;
	}
    a=a+(b*d);
    printf("%d\n",a);
  }
  printf("%d\n",a);
  return 0;
}
