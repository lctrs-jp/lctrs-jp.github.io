#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30
#define LEN 200

struct attendance {
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};
typedef struct attendance ATTEND;

int load(ATTEND item[MAX], char *file);


int main(int argc,char *argv[])
{
  ATTEND item[MAX];
  int i, number, n, year, month, day;
  
  if(argc != 4)
    {printf("Usage:%s file1 file2 file3\n",argv[0]);
      exit(1);
    }
  for(i = 1; i < argc; i++)
    {number = load(item, argv[i]);
    }
  
  for(i = 0; i < number; i++){
    n = item[i].date;
    day = n % 100; month = (n / 100) % 100; year = n / 10000;
    

    printf ("date\t\tAlice\tBob\tCarol\n");
    printf ("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	    year,month,day,item[i].alice,item[i].bob,item[i].carol,
	    item[i].ok,item[i].unfixed );
  }
  return 0;
}

int load(ATTEND item[MAX], char *file)
{e
  FILE *fp;
  char buf[LEN],name[LEN], schedule[LEN], date[9];
  int len, number;
  
  if((fp = fopen (file, "r")) == NULL)
    {printf("can not open the file %s\n",file);
      exit(1);
    }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if(len > 0 &&  buf[len - 1] =='\n') buf[len - 1] = '\0';
  sscanf(buf,'#%s', name);

  number = 0;
  while(fgets(buf, LEN, fp) != NULL)
    {
      len = strlen(buf);
      if(len > 0 && buf[len - 1] =='\n') buf[len - 1] = '\0';
      
      sscanf(buf,"%s %s", date, schedule);
      item[number].date = date;
      number ++;

      item[number].ok = 0;
      item[number].unfixed = 0;
      if(schedule == 'o') item[number].ok = item[number].ok + 1;
      if(schedule == '?') item[number].unfixed = item[number].unfixed + 1;

      if(strcmp(name, "Alice") == 0) item[number].alice = schedule;  
      if(strcmp(name, "Bob") == 0) item[number].bob = schedule;
      if(strcmp(name, "Carol") == 0) item[number].carol = schedule;
    }
  return number;
}
