#include<string.h>
#include<stdio.h>
 

int main(int argc, char *argv[])
{

  int i,j,souwa=0;
  int a =0;

  j = strlen(argv[1]);
 

  for(i =0; i < j; i++){ 
    souwa = *(argv[1] + i);     
 souwa = 26 * a + souwa;
 a = souwa - 64;
  } 


  printf("%d", a);



  return 0;
}
