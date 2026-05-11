#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 273

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
}; 


typedef struct attendance ATTENDANCE;
 

int main(int argc, char *argv[])
{
  // struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };

  /*  struct attendance {
    char date[9]; // 日にち
    char alice;   // Aliceの都合
    char bob;     // Bobの都合
    char carol;   // Carolの都合
    int ok;       // 参加可能な人数
    int unfixed;  // 参加未定（?）の人数
 };*/

  ATTENDANCE item[MAX],arv; 
  FILE *fp, *ip, *op;
  char buf[LEN], abuf[LEN], bbuf[LEN], cbuf[LEN], ox[LEN];
  char alice[LEN], bob[LEN], carol[LEN];
  int n, year, month, day;
  int i, size, total, len;

  if (argc != 4 ){ //引数の確認
    printf("Usage: %s <filename> <filename> <filename>\n", argv[0]);
    exit(1);
  }

  //ファイルおーぺん
  if  ((fp = fopen (argv[1], "r")) == NULL ){
      printf ("ファイル %s のおーぺんに失敗しました\n", argv[1]);
      exit(1);
    }

  if  ((ip = fopen (argv[2], "r")) == NULL){
      printf ("ファイル %s のおーぺんに失敗しました\n", argv[2]);
      exit(1);
    }

  if  ((op = fopen (argv[3], "r")) == NULL){
      printf ("ファイル %s のおーぺんに失敗しました\n", argv[3]);
      exit(1);
    }


    //改行記号消す

    fgets(buf,LEN,fp);
    len = abuf(buf);
    if(len>0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    strcpy(abuf,&buf[1]);
    printf("%s\n",abuf);    


    fgets(buf,LEN,ip);
    len = bbuf(buf);
    if(len>0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    strcpy(bbuf,&buf[1]);
    printf("%s\n",bbuf);    


    fgets(buf,LEN,op);
    len = cbuf(buf);
    if(len>0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    strcpy(cbuf,&buf[1]);
    printf("%s\n",cbuf);    

    size = 0;
    total = 0;
    while (fgets(buf,LEN,fp) != NULL){
      len = strlen(buf);
      if(len > 0 && buf[len-1]=='\n')
	buf[len-1] = '\0';

     
      for(i = 0 ; i < len; i++){
	sscanf( abuf, "%d %c", &n, ox );
	abuf.day[i] = n % 20150100;
	abuf.month[i] = (n / 100) % 100;
	abuf.year[i] = n / 10000;
	alice[i] = ox;
      }
     
      for(i = 0 ; i < len; i++){
	sscanf(bbuf, "%c", ox);
	bob[i] = ox;
      }

      for(i = 0 ; i < len; i++){
	sscanf(cbuf, "%c", ox);
	carol[i] = ox;
      }


      printf("date\t\tAlice\tBob\tCarol\n");

      printf("-------------------------------------");

      printf("%4d/%2d/%2d\t%c\t%c\t%c",
	     &year, &month, &day,
	     &item.alice, &item.bob, &item.carol
	     );
      
      printf("-------------------------------------");
 
  
      /*  size++;
      printf("id:%d\t%3d\n",id,score);
    }
    printf("Avg:\t%3d\n",total/size);
      */    
    fclose(fp);
    fclose(op);
    fclose(ip);

    
    
    /*  sscanf( item.date, "%d", &n );
  day = n % 20150100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol,
	 item.ok, item.unfixed );*/


  return 0;
}
