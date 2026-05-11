#include <stdio.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}a[100];

int main(char str,char file[])
{
  FILE *fp;
  int i,x,y,z;
  char *b[50];
  int o[50],p[50],q[50];

  sscanf(str,"%d/%d/%d",&x,&y,&z); 
  
  if((fp=fopen("file","w"))==NULL){
    printf("ファイルを開くことができません。\n");
    exit(1);
  }

  for(i=0;;){
    fgets(b[i],50,fp);
    sscanf(b[i],"%d/%d/%d",&a[i].year,&a[i].month,&a[i].day);
    if(a[i].year>=x||a[i].month>y||a[i].day>=z){
      printf("%s",b[i]);
    }
    i++;
    if(!feof(fp)){
	break;
      }
      }

  fclose(fp);

  return 0;
}
