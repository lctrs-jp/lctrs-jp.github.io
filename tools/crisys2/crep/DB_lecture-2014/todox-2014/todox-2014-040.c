#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo todo1;
 
todo1 list[MAX]; 
int n = 0; 


void load(FILE *fp);
void display(void);
int split(char buf[], char *out[]);

int main(int argc, char *argv[])
{
  FILE *fp;
  int i;
  
  
  if (argc < 2)
    {
    fprintf(stderr,"ファイルが指定されていません\n", argv[0] );
    exit(1);
    }
  else
    {
      for (i = 0; i < 4; i++) 
	{
	  if( (fp = fopen(argv[i+2],"r")) == NULL)
	    {
	      fprintf(stderr,"エラー：ファイルを開けません\n", argv[i+2]);
	      exit(1);
	    }
	  load(fp);
	  fclose(fp);
	}
      display();
      return 0;
    }
}
void load(FILE *fp)
{
  int i,len;
  char buf[MAX], content[MAX];
  char *out[MAX];
  int date,time;
  
  
  while(fgets(buf, MAX, fp) != NULL)
{
    if( (len = strlen(buf)) > 0 && buf[len-1] == '\n' )
      {
	buf[len -1] = '\0';
      }
    i = split(buf,out);
    date = atoi(out[0]);
    time = atoi(out[1]);
    
    if (i == 4)
      {
	list[n].year = date / 10000;
	list[n].month = (date / 100) % 100;
	list[n].day = date % 100;
	list[n].hour = time / 100;
	list[n].minute = time % 100;
	strcpy(list[n].content,out[2]);
	n++;
      }
    if (n >= MAX) 
      {
	fprintf(stderr,"メモリーを超えています\n");
	exit(1);
      }
 }
  return;
}


void display(void)
{
  int i;
  
  
  if(n < 1) 
    {
      printf("データがありません\n");
      return;
    }
  for(i = 0; i <n ; i++) 
    {
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n",list[i].year,list[i].month,list[i].day,list[i].hour,list[i].minute,list[i].content);
    }
   return;
}



int split(char buf[], char *out[])
{
  int n = 0;                
  
 while (*buf)
   {           
     for (;*buf == ' ';buf++);     
     if (*buf != '\0')
       {
	 *out++ = buf;             
	 n++;                
       }
     
     for (;*buf != ' ' && *buf != '\0';buf++);     
     if (*buf ==' ')         
       *buf++ = '\0';
   }
 
 return n;
}







		  
