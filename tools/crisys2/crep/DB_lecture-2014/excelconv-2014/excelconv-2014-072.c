#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a,b,c,t,i;
  c = 0;
  for(i = 0; i <= 4; i++){
    a = 1;
    if(*(argv[1]+i) != '\0'){
      b = strlen(argv[1]+i);
      for(t = 1; t < b; t++)
	{
	  a = a * 26;
	}	
      c = c + ((*(argv[1]+i)-64) * a);
    }
    else{
      printf("%d\n",c);
      
      return 0;
    }
  }
}

