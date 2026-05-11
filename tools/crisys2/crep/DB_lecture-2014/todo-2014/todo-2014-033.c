#include <stdio.h>
#include <string.h>

#define MAX 100;

typedef struct _todo{
int year;
int month;
int day;
int hour;
int minute;
char content[256];
}todo;

todo list[100];

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char buf[MAX];
  char time[MAX];
  char timelist[MAX][MAX];
 
  int len, i, j, k, l = 0, end = 0;

  if(argc != 3){
    printf("Error\n");
    return 0;
  }

  if((fp1 = fopen(argv[1],"r"))==NULL){
    fprintf(stderr,"Error\n");
    exit(1);
  }

  for(;;)
    if((time = fgetc(fp1))==EOF)
      break;

  if((fp2 = fopen(argv[2],"r"))==NULL){
    fprintf(stderr,"Error\n");
    exit(1);
  }

  i = 0;

  while(fgets(buf, MAX, fp2) != NULL){
    if((len = strlen(buf)) > 0 && buf[len-1] == '\n'){
      len--;
      buf[len] = '\0';
    } 
    sscanf(buf,"%.4d/%.2d/%.2d %.2d:%.2d %s",&list[i].year, &list[i].month, &list[i].day, &list[i].hour, &list[i].minute, &list[i].content);
    i++;
  }

  for(j = 0; end != 1; j++){
    for(i = 0; end != -1; i++){
      timelist[j][i] = buf[i+k];
      if(buf[i] == '\0'){
	end = 1;
	l = i;
      }
      if(buf[i] == '\n'){
	end = -1;
	k = i;
      }
    }
  }

  for(i = 0; end != 1;i++){
    if(strncmp(time,timelist[i],16) < 0)
      for(j = 0; ;j++){
	printf("%s",timelist[j]);
      if(timelist[j] == '\0'){
	printf("\n");
	break;
      }
      }
    if(i >= l)
      break;
  }

return 0;
}
