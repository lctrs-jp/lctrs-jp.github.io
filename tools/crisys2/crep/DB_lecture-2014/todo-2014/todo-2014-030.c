#include <stdio.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
struct todo work[100];
int tannyao(struct todo a);
int main(int argc, char *argv[])
{
  FILE *fp;
  char x[100];
  int i,a,b,c;
  sscanf(argv[1],"%d/%d/%d",&a,&b,&c);

  if((fp = fopen("*argv[2]","r"))==NULL)
    {
      printf("ファイルが見つかりません\n");
    }
  for(i=0;;i++)
  for(;;){
    if((x[i] = fgetc(fp+i)) == EOF)
      break;
    for(i=0;x[i]!=EOF;i++)
    sscanf(x[i],"%d/%d/%d %d:%d %c",&work[i].year,&work[i].month,&work[i].day,
	   &work[i].hour,&work[i].minute,&work[i].content);
  }
    for(i=0;x[i]!=EOF;i++){
      if(a-work[i].year>0){}
      else if(a-work[i].year<0){
	tannyao(work[i]);
      }
      else if(b-work[i].month==0 && c-work[i].day<0)
	tannyao(work[i]);
      else if(b-work[i].month<0)
	tannyao(work[i]);
   

      fclose(fp);
      return 0;
    }
}
    
    int tannyao(struct todo a)
{
  printf("%4d/%2d/%2d %2d:%.2d %s\n", a.year,a.month,
	 a.day,a.hour, a.minute, a.content);
  return 0;
}
