#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define LEN 80

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
  struct attendance item[MAX]; 
  int len, i, n, size, year, month, day;
  FILE *fp1, *fp2, *fp3;
  char buf[LEN], sub[LEN];  
  
  //引数の数を確認
  if(argc != 4){
    printf("Usage: %s <filename1(Alice)> <filename2(Bob)> <filename3(Carol)> \n", argv[0]);
    exit(1);
  }

  //Alice
  if ((fp1 = fopen (argv[1], "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました\n", argv[1]);
    exit (1);
  }

  fgets(sub, LEN, fp1);
  len = strlen(sub);
  if(len > 0 && sub[len - 1] == '\n'){
    sub[len - 1]= '\0';
  }

  for(i = 0; i < len ; i++){
    sub[i] = sub[i + 1];
  }

  size = 0;
  while(fgets(buf, LEN, fp1) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n'){
      buf[len - 1] = '\0';
      sscanf(buf, "%9c %s\n", &item[size].date, &item[size].alice);
      size++;
    }else{
      printf("Format error\n");
      exit(1);
    }
  }

  fclose(fp1);
  

  //Bob
  if ((fp2 = fopen (argv[2], "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました\n", argv[2]);
    exit (1);
  }

  fgets(sub, LEN, fp2);
  len = strlen(sub);
  if(len > 0 && sub[len - 1] == '\n'){
    sub[len - 1]= '\0';
  }

  for(i = 0; i < len ; i++){
    sub[i] = sub[i + 1];
  }

  size = 0;
  while(fgets(buf, LEN, fp2) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n'){
      buf[len - 1] = '\0';
      sscanf(buf, "%9c %s\n", &item[size].date, &item[size].bob);
      size++;
    }else{
      printf("Format error\n");
      exit(1);
    }
  }
 
  fclose(fp2);

  //Carol
  if ((fp3 = fopen (argv[3], "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました\n", argv[3]);
    exit (1);
  }

  fgets(sub, LEN, fp3);
  len = strlen(sub);
  if(len > 0 && sub[len - 1] == '\n'){
    sub[len - 1]= '\0';
  }

  for(i = 0; i < len ; i++){
    sub[i] = sub[i + 1];
  }

  size = 0;
  while(fgets(buf, LEN, fp3) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n'){
      buf[len - 1] = '\0';
      sscanf(buf, "%9c %s\n", &item[size].date, &item[size].carol);
      size++;
}else{
  printf("Format error\n");
  exit(1);
 }
}

  fclose(fp3);

  //年月日を処理
sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  //表示
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");
  for(i = 0; i < size; i++){
    sscanf( item.date[i], "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
         year, month, day, item.alice[i], item.bob[i], item.carol[i]);
  }
  printf("--------------------------------------\n"); 


 printf("%4d/%2d/%2d\t[o:%d, ?:%d]\n",
	 year, month, day, item.ok, item.unfixed );

  return 0;
}
