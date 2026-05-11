#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30

struct attendance {
  char date[9];
  char alice;
  char bob;
  char carol;
};

typedef struct attendance ATTENDANCE;

int main(int argc, char *argv[])
{
  ATTENDANCE item[MAX];
  int a, i, n, year, month, day, size = 0, len;
  FILE *fp;
  char buf[256], name[256], att, date[256];

  for(a = 1; a < argc; a++)  {
      if((fp = fopen(argv[a], "r")) == NULL)  {
          printf("Cannot open txt file.\n");
	  exit(1);
	}
      fgets(buf, 256, fp);
      len = strlen(buf);
      if(len > 0 && buf[len - 1] == '\n')
	buf[len - 1] = '\0';
      sscanf(buf, "#%s", name);

      while( fgets(buf, 256, fp) != NULL) {
	len = strlen(buf);
	if(len > 0 && buf[len - 1] == '\n')
	  buf[len - 1] = '\0';
	sscanf(buf, "%s %c"  ,date, &att);
	for(i = 0; i < size; i++) {
	  if(strcmp(date, item[i].date) == 0){

	    if(strcmp(name, "Alice") == 0)
	      item[i].alice =  att;
	    else if(strcmp(name, "Bob") == 0)
	      item[i].bob = att;
	    else if(strcmp(name, "Carol") == 0)
	      item[i].carol = att;
	    else 
	      printf("Wrong name error : %s\n", name);
	    break;
	 
           }
	}
	if(i == size) {
	  strcpy(item[i].date, date);

	    if(strcmp(name, "Alice") == 0)
	      item[i].alice =  att;
	    else if(strcmp(name, "Bob") == 0)
	      item[i].bob = att;
	    else if(strcmp(name, "Carol") == 0)
	      item[i].carol = att;
	    else 
	      printf("Wrong name error : %s\n", name);

	  size++;
	}
      }   //  while( fgets(buf, 256, fp) != NULL) {に対応
  }    //  for(a = 1; a < argc; a++)  { に対応


  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-----------------------------------------\n");

  for(i = 0; i < size; i++) {

  sscanf(item[i].date, "%d", &n);
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

    printf("%4d/%2d/%2d\t%c\t%c\t%c\n", year, month, day, item[i].alice, item[i].bob, item[i].carol);

  }

  printf("------------------------------------------\n");

  return 0;
}
