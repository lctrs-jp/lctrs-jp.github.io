#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
  int day;
  int month;
  int year;
};

void sort(struct attendance item[], int n);

int main(int argc, char *argv[])
{
  struct attendance item[MAX]; 
  int n, num,check ;
  int i;
  FILE *fp;
  char c;
  char buf[MAX], date[9];
  if (argc != 4){
    printf("Usage: ./ex2 alice.txt bob.txt carol.txt\n");
  return 0;
} 
  if ((fp = fopen(argv[1], "r")) == NULL) { /* ファイルのオープン */
    printf("%s を開けませんでした\n", argv[1]);
    return;
  }
  fgets(buf,MAX,fp);
  if (strncmp(buf,"#Alice",6) != 0){ /* Alice */
    printf("Usage: ./ex2 alice.txt bob.txt carol.txt\n");
    return 0;
  }
  
  while(fgets(buf,MAX,fp) != NULL){
    sscanf(buf,"%s %c", date, &c);
      strcpy(item[i].date,date);
      item[i].alice = c;
      i++;
    }
  fclose(fp);
  num = i;
  
  if ((fp = fopen(argv[2], "r")) == NULL) { /* ファイルのオープン */
    printf("%s を開けませんでした\n", argv[2]);
    return;
  }
  fgets(buf,MAX,fp);
  if (strncmp(buf,"#Bob",4) != 0){ /* Bob */
    printf("Usage: ./ex2 alice.txt bob.txt carol.txt\n");
    return 0;
  }

  while(fgets(buf,MAX,fp) != NULL){
    check = 0;
    sscanf(buf,"%s %c", date, &c);
    for (i=0;i <= num; i++){
      if(strcmp(date,item[i].date) == 0) /* 構造体に入ってるデータと日付が一致したらそこに入れる */
	item[i].bob = c;
      check = 1;
    }
    if (check != 1) { /* 日付が入ってない場合 */
      strcpy(item[i].date, date);
      item[i].bob = c;
      num = num + 1;
    }
  }

  fclose(fp);

  if ((fp = fopen(argv[3], "r")) == NULL) { /* ファイルのオープン */
    printf("%s を開けませんでした\n", argv[3]);
    return;
  }
  fgets(buf,MAX,fp);
  if (strncmp(buf,"#Carol",6) != 0){ /* Carol */
    printf("Usage: ./ex2 alice.txt bob.txt carol.txt\n");
    return 0;
  }

  while(fgets(buf,MAX,fp) != NULL){
    check = 0;
    sscanf(buf,"%s %c", date, &c);
    for (i=0;i <= num; i++){
      if(strcmp(date,item[i].date) == 0) /* 構造体に入ってるデータと日付が一致したらそこに入れる */
        item[i].carol = c;
      check = 1;
    }
    if (check != 1) { /* 日付が入ってない場合 */
      strcpy(item[i].date, date);
      item[i].carol = c;
      num = num + 1;
    }
  }

  fclose(fp);

  for(i = 0; i < num; i++){
  sscanf( item[i].date, "%d", &n );
  item[i].day = n % 100;
  item[i].month = (n / 100) % 100;
  item[i].year = n / 10000;
  }
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("------------------------------\n");
  for (i = 0; i < num; i++){ 
  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	 item[i].year, item[i].month, item[i].day,
	 item[i].alice, item[i].bob, item[i].carol);
  item[i].ok = 0;
  item[i].unfixed = 0;
  if (item[i].alice == 'o')
    item[i].ok = item[i].ok + 1;
  else if(item[i].alice == '?')
    item[i].unfixed = item[i].unfixed + 1;
  if (item[i].bob == 'o')
    item[i].ok = item[i].ok + 1;
  else if(item[i].bob == '?')
    item[i].unfixed = item[i].unfixed + 1; 
  if (item[i].carol == 'o')
    item[i].ok = item[i].ok + 1;
  else if(item[i].carol == '?')
    item[i].unfixed = item[i].unfixed + 1; 
}
  printf("%d\n",num);
 printf("------------------------------\n");
  sort(item,num);
  for (i = 0; i < num; i++)
  printf("%4d/%2d/%2d\t[ok:%d, ?:%d]\n",
         item[i].year, item[i].month, item[i].day,
         item[i].ok, item[i].unfixed);

 

  return 0;
}

void sort(struct attendance item[], int n) {
  struct attendance temp;
  int i,j;

  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (item[j].ok - item[j-1].ok > 0){
        temp = item[j];
        item[j] = item[j - 1];
        item[j - 1] = temp;
      }
    }
  }

  return;
}
