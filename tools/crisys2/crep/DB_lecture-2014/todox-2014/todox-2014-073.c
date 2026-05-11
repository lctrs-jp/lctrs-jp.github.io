#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
  struct event item[100];
  int i, j, k = 0, n, date, time, len;
  FILE *fp;
  char *out[100], buf[256];
 
  for(i = 0; i < k; i++)
    printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year, item[i].month,
	   item[i].day, item[i].hour, item[i].minute, item[i].content );
  return 0;
}  
 
for(i = 1 : i < argc : i++){
while( fgets(buf,256,fp) != NULL){
  sscanf(buf,"%d:%d:%d". &year, &month, &day);
  n = split(buf, out);
  if( n == 0) continue;
  else  {
    date = atoi(out[0]);
    item[k].year = date / 10000;
    item[k].month = (date % 10000) / 100;
    item[k].day = (date % 100);
    time = atoi (out[1]);
    item[k].hour = time /100;
    item[k].minute = time % 100;
    strncpy( item[k].content, out[2], 256);
    k++;
  }
 }

 fclose( fp );
 }
 
    
