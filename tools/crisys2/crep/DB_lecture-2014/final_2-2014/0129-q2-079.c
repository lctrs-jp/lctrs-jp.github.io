#include <stdio.h>
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
  struct attendance item[200];
  int n, year[12], month[12], day[12];
  int i, k, elem, t, date, len, size;
  FILE *fp;
  char buf[50], name[50];

  if(argc < 2){
    printf("Usage: %s filename1 ... filename2\n", argv[0]);
    exit(1);
  }

  for (i = 1; i < argc; i++){
    if((fp = fopen(argv[i], "r")) == NULL){
      fprintf(stderr, "Error: can't open \"%s\.\n", argv[i]);
      exit(1);
    }

    while(fgets(buf, 50, fp) != NULL){
      if(buf[0] == '\0' || buf[0] == '\n' || buf[0] == '#')
	continue;
      if(sscanf(buf, "%s %d %s", name, &date, t) != 3){
	fprintf(stderr, "Error: format is illegal (\"%s\"in %s)\n", buf, argv[i]);
	exit(1);
      }
      /* メインの動作 */
      fgets(buf, MAX, fp);
      len = strlen(buf);
      if(len > 0 && buf[len-1] == '\n')
	buf[len - 1] = '\0';
      strcpy(name, &buf[1]);
      while(fgets(buf, MAX, fp) != NULL){
	len = strlen(buf);
	if(len > 0 && buf[len - 1] == 'n')
	  buf[len - 1] = '\0';
	sscanf(buf, "%s %d %s", name, &date, t);
	for(i = 0; i < size; i++)
	  if(strcmp(name, name[i]) == 0){
	    break;
	  }
      }
    }
  }









     for(i = 0; i < 12; i++){
      strncmp( item[i].date, "%d", &n );
      day[i] = n % 10;
      month[i] = (n / 100) % 100;
      year[i] = n / 10000;
     }

  printf("date\t\tAlice\tBob\tCarol\n");
  for(i = 0; i < k; i++)
   printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year[i], month[i], day[i],
	 item[i].alice, item[i].bob, item[i].carol,
	 item[i].ok, item[i].unfixed );

  return 0;
}
