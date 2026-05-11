#include <stdio.h>

int split(char buf[], char *out[]); 

int main(void)
{
  int n;

  char word[100];
  char *o[100];

  fgets(word, 100, stdin);
  
  for(n = 0; n != split(word, o) - 1; n++)
  printf("%s ", o[n]);

  return 0;
}

int split(char buf[], char *out[]){
  int a;
  int b = 0;
  int x = 1;

  for(a = 0; buf[a] == ' '; a++)
    ;

  while(buf[a] != '\0'){
    buf[b] = buf[a];
    b++;
	a++;
  }

  buf[b] = '\0';

  if(buf[0] == '\0')
    x = 0;

  out[0] = &buf[0];

  for(a = 0; buf[a] != '\0'; a++){
    if(buf[a] == ' ' && buf[a + 1] != ' ' && buf[a + 1] != '\0'){
	  out[x] = &buf[a + 1];
	  x++;
	}
	if(buf[a] == ' ')
	  buf[a] = '\0';
  }

  return x;
}
