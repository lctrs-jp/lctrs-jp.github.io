#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct attendance{
  int date; //日にち
  int day; //日
  int month; //月
  int year; //年
  char alice[2]; //Aliceの都合
  char bob[2]; //Bobの都合
  char carol[2]; //Carolの都合
  int ok; //参加可能な人数
  int unfixed; //参加未定(?)の人数
};

typedef struct attendance ATT;
ATT plan[MAX];

int main(int argc, char *argv[])
{
  FILE *fp[3];
  int i, size=0, j, k=0, date;
  char temp[10], buf[20], t[3];

  if(argc != 4){
    printf("引数が不正です\n");
    exit(1);
  }

  for(i=0; i<3; i++)
    if((fp[i] = fopen(argv[i+1], "r")) == NULL){
      printf("ファイルオープンエラー\n");
      exit(1);
    }
  for(i = 0; i < 3; i++){
    fgets(temp, 10, fp[i]);
    while(fgets(buf, 20, fp[i])){
      sscanf(buf, "%d %s", &date, t);
      for(j=0; j<size; j++)
	if(date == plan[j].date){
	  k++;
	  if(i==0)
	    sscanf(t, "%s", plan[j].alice);
	  else if(i==1)
	    sscanf(t, "%s", plan[j].bob);
	  else
	    sscanf(t, "%s", plan[j].carol);
	}
      if(k == 0){
	plan[size].date = date;
	if(i==0)
	  sscanf(t, "%s", plan[size].alice);
	else if(i==1)
	  sscanf(t, "%s", plan[size].bob);
	else
	  sscanf(t, "%s", plan[size].carol);
	size++;
      }
    }
  }

  for(i=0; i<size; i++){
    plan[i].day = plan[i].date % 100;
    plan[i].month = (plan[i].date / 100) % 100;
    plan[i].year = plan[i].date / 10000;
  }

  for(i=0; i<size; i++){
    plan[i].alice[1] = '\0';
    plan[i].bob[1] = '\0';
  }

  for(i=0; i<size; i++){
    plan[i].ok = 0;
    plan[i].unfixed = 0;
  }

  for(i=0; i<size; i++){
    if(plan[i].alice[0] == 'o')
      plan[i].ok++;
    else if(plan[i].alice[0] == '?')
      plan[i].unfixed++;

    if(plan[i].bob[0] == 'o')
      plan[i].ok++;
    else if(plan[i].bob[0] == '?')
      plan[i].unfixed++;

    if(plan[i].carol[0] == 'o')
      plan[i].ok++;
    else if(plan[i].carol[0] == '?')
      plan[i].unfixed++;
  }

  printf("Date\t\tAlice\tBob\tCarol\n");
  for(i=0; i<40; i++)
    printf("-");
  printf("\n");

  for(i=0; i<size; i++){
    printf("%d/%2d/%2d\t%s\t%s\t%s\n", plan[i].year, plan[i].month, plan[i].day, plan[i].alice, plan[i].bob, plan[i].carol);
  }

  for(i=0; i<40; i++)
    printf("-");
  printf("\n");

  for(i=0; i<size; i++)
    printf("%d/%2d/%2d [ok:%d, ?:%d]\n", plan[i].year, plan[i].month, plan[i].day, plan[i].ok, plan[i].unfixed);

  for(i=0; i<3; i++)
    fclose(fp[i]);

  return 0;
}
