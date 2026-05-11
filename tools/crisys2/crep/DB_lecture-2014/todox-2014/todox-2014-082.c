#include <stdio.h>
#include <string.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item[100];

int main(int argc, char *argv[])
{
  char buf[256];
  FILE *fp;
  int len, j;
  int i = 0;

  if( argc == 2 ){
    if( (fp = fopen(argv[1],"r") ) != NULL ){
      while( fgets(buf,256,fp) != NULL ){
	len = strlen(buf);
	if(len > 0 && buf[len - 1] == '\n') 
	  buf[len - 1] = '\0';
	if(buf[0] != '\n'){
	  sscanf(buf, "%d/%d/%d %d:%d", &item[i].year, &item[i].month, &item[i].day, &item[i].hour, &item[i].minute);
	strcpy(item[i].content, buf + 17 );
	i++;	
	}
      }

      fclose(fp);

      for( j = 0; j < i; j++ )  
	printf("%4d/%2d/%2d %2d:%.2d %s\n", item[j].year, item[j].month, item[j].day, item[j].hour, item[j].minute, item[j].content);

    }
  }

  return 0;
}
