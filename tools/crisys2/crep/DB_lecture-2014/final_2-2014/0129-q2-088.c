#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 273
#define MAX 30


struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTENDANCE;
void print(ATTENDANCE d[MAX],int size,ATTENDANCE arg);
int load (ATTENDANCE d[MAX], char *filename,int size);



int main(int argc, char *argv[])
{
  ATTENDANCE students[MAX],avg;
  int i,size;

  if (argc<2){
    printf("Usage: %s filename1...filename2\n", argv[0]);
    exit(1);
  }

  for (i=1;i<argc;i++){
    size = load(students,argv[i],size);
}

  print(students,size);
  return 0;
}

int load(ATTENDANCE d[MAX],char *filename,int size)
{
  FILE *fp;
  char buf[LEN],person[LEN];
  char date[50];
  int len,id,attendance,i;

  if((fp=fopen(filename, "r"))==NULL){
    printf("ファイル %s のオープンに失敗しました", filename);
    exit(1);
  }
  fgets(buf,LEN,fp);
  len = strlen(buf);
  if (len>0 && buf[len-1]=='\n')
    buf[len-1]='\0';
  strcpy(person,&buf[1]);

  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len>0 && buf[len-1]=='\n')
      buf[len-1]='\0';
    sscanf(buf,"%s %d", date, &attendance);
    for(i=0;i<size;i++){
      if(strcmp(date,d[i].date)==0){
	id=i;
	break;
      }
    }
    if(i ==size){
      strcpy(d[i].date,date);
      id = size;
      size++;
    }

    if (strcmp(person,"alice")==0)
      d[id].alice = attendance;
    else if (strcmp(person,"bob")==0)
      d[id].bob= attendance;
    else if (strcmp(person,"carol")==0)
      d[id].carol=attendance;
    else
      printf("Wrong person error: %s\n",person);
  }
  return size;
}
  
void print(ATTENDANCE d[MAX],int size, ATTENDANCE avg)
{
  int i;
  printf("date\talice\tbob\tcarol\n");
  printf("----------------------------------\n"); 
 for (i=0;i<size;i++){
    printf("%4d/ %2d/ %2d\t%s\t%s\t%s\n",
	   d[i].date,d[i].alice,d[i].bob,
	   d[i].carol);
  }
  printf("----------------------------------\n");
}
