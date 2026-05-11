#include <stdio.h>
#include <string.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

int main(int argc, char *argv[])
{
  int i;
  FILE *fa = NULL, *fb = NULL, *fc = NULL;
  if(argc != 4){
    printf("argc is wrong\n");
    return 1;
  }
  for(i = 0; i < 3; i++){
    if(!strcmp(argv[i + 1], "alice.txt") && (fa == NULL)){
      if((fa = fopen(argv[i + 1], "r")) == NULL){
	printf("filed open file\n");
	return 1;
      }
    }
    else if(!strcmp(argv[i + 1], "bob.txt") && (fb == NULL)){
      if((fb = fopen(argv[i + 1], "r")) == NULL){
	printf("filed open file\n");
	return 1;
      }
    }
    else if(!strcmp(argv[i + 1], "carol.txt") && (fc == NULL)){
      if((fc = fopen(argv[i + 1], "r")) == NULL){
	printf("filed open file\n");
	return 1;
      }
    }
    else{
      printf("argv%d is wrong\n", i + 1);
      return 1;
    }
  }//３つのファイルを開く

  struct attendance item[MAX];
  int j, flag = 1, mem = 0;//mem:日数
  char fuck[8];//ごみ
  char line[12], empt[12] = "\0\0\0\0\0\0\0\0\0\0\0\0";
  fgets(fuck, 8, fa);
  for(i = 0; flag; i++){
    strcpy(line, empt);
  	if((fgets(line, 12, fa)) == NULL) break;
    j = strlen(line);
    if(line[j - 1] == '\0'){
      line[j - 1] = '\n';
      line[j] = '\0';
      flag--;
    }
    sscanf(line, "%s %c\n", item[i].date, &(item[i].alice));
    mem++;
  }
  //aliceの書き込み

  int dflag;
  flag = 1;
  fgets(fuck, 8, fb);
  for(i = 0; i < mem; i++){
    item[i].bob = ' ';
  }
  while(flag){
    strcpy(line, empt);
  	if((fgets(line, 12, fb)) == NULL) break;
    j = strlen(line);
    if(line[j - 1] == '\0'){
      line[j - 1] = '\n';
      line[j] = '\0';
      flag--;
    }
    dflag = 1;
    for(i = 0; i < mem; i++){
      if(!strncmp(line, item[i].date, 8)){
	  sscanf(line, "%s %c\n", fuck, &(item[i].bob));
	  dflag = 0;
      }
    }
    if(dflag){
      sscanf(line, "%s %c\n", item[mem].date, &(item[mem].bob));
      item[mem].alice = ' ';
      mem++;
    }
  }
  //bobの書き込み

  flag = 1;
  fgets(fuck, 8, fc);
  for(i = 0; i < mem; i++){
    item[i].carol = ' ';
  }
  while(flag){
    strcpy(line, empt);
  	if((fgets(line, 12, fc)) == NULL) break;
    j = strlen(line);
    if(line[j - 1] == '\0'){
      line[j - 1] = '\n';
      line[j] = '\0';
      flag--;
    }
    dflag = 1;
    for(i = 0; i < mem; i++){
      if(!strncmp(line, item[i].date, 8)){
	  sscanf(line, "%s %c\n", fuck, &(item[i].carol));
	  dflag = 0;
      }
    }
    if(dflag){
      sscanf(line, "%s %c\n", item[mem].date, &(item[mem].carol));
      item[mem].alice = ' ';
      item[mem].bob = ' ';
      mem++;
    }
  }//carolの書き込み

  printf("date\t\tAlice\tBob\tCarol\n");
  for(i = 0; i < 37; i++) putchar('-');
  putchar('\n');
  for(i = 0; i < mem; i++){
    int n, year, month, day;
    sscanf( item[i].date, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day,
	   item[i].alice, item[i].bob, item[i].carol);
  }
  for(i = 0; i < 37; i++) putchar('-');
  putchar('\n');

  return 0;
}
