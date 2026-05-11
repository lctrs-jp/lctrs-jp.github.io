#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256

void input(char *filename ,int num);

struct date{
  char name[LEN];
  int day[LEN];
  int month[LEN];
  int year[LEN];
  char ok[LEN];
};

struct date item[LEN];

int days[LEN];

int main(int argc, char *argv[])
{
  
  int i, j, k, day, maxitem;
  
  for(i = 1;i < argc; i++)
    input(argv[i],i);
  
  if(days[1] >= days[2])
    {
      if(days[1] >= days[3])
	{
	  day = days[1];
	  maxitem = 1;
	}
      else 
	{
	  day = days[3];
	  maxitem = 3;
	}
    }
  
  else
    {
      if(days[2] >= days[3])
	{
	  day = days[2];
	  maxitem = 2;
	}
      else
	{
	  day = days[3];
	  maxitem = 3;
	}
    }
  
  printf("date\t");
  for(i = 1; i < argc; i++)
    printf("%s\t",item[i].name);
  
  printf("\n------------------------------\n");
  
  for(j = 0; j < day; j++)
    printf("%d/ %d/%d\t",item[maxitem].year[j],item[maxitem].month[j],item[maxitem].day[j]);
  for(i = 1; i < argc; i++)
    for(k = 0; k < days[i]; k++)
      if(item[maxitem].year[j] == item[i].year[k])
	if(item[maxitem].month[j] == item[i].month[k])
	  if(item[maxitem].day[j] == item[i].day[k])
	    {
	      printf("%c",item[i].ok[k]);
	    }	      
  
  
  return 0;
}


void input(char *filename ,int num)
{


  FILE *fp;
  char buf[LEN][LEN];
  int i, n ,len, buflen;
  char c;

  i = 0;

  if((fp = fopen(filename, "r")) == NULL){
    printf("%d番目のファイルのオープンに失敗しました\n",num);
    exit(1);
  }



  while(fgets(buf[i],LEN,fp) != NULL)
    {
      len = strlen(buf[i]);
      if(len > 0 && buf[i][len-1] == '\n')
        buf[i][len-1] = '\0';
      buflen = i;
      i++;
    }

  days[num] = i;

  fclose(fp);

  sscanf(buf[0],"#%s",item[num].name);

  i = 0;

  while(i < buflen)
    {
      sscanf(buf[i+1] ,"%d %c", &n, &c);
      item[num].day[i] = n % 100;
      item[num].month[i] = (n / 100) % 100;
      item[num].year[i] = n / 10000;
      item[num].ok[i] = c;

      /*      printf("%d/%d/%d %c\n",item[num].year[i],item[num].month[i],item[num].day[i],item[num].ok[i]);

       */
      i++;
    }


}
