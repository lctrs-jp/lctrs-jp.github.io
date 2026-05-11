#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define LEN 273

  struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
}AT[MAX];

int main(int argc,char *argv[]){
  FILE *fp[MAX];
  int a,n, id,year, month, day, len,count;
  char buf[LEN],name[LEN],mark,cdate[MAX];

  id=1;

  if( argc !=  4){
    printf("./out ***.txt ***.txt ***.txt\nの形で入力してください。\n");
    exit(1);
  }
  for( n = 1; n <= 3; n++ ){
      if(( fp[n] = fopen( argv[n], "r" )) == NULL ){
        printf("ファイルを開くことができません。\n");
        exit(1);
      }
  }
 
  if (fgets(buf,MAX,fp[1]) != NULL){
        len = strlen (buf);
        //printf("%s\n", buf);printf("%d\n", len);
      if(len>0 && (buf[len-1] == '\n')){
        buf[len-1] = '\0';
        sscanf( buf, "#%s", name); //個人を特定
        //printf("%s\n",name);
        while (fgets(buf,MAX,fp[1]) != NULL){ //一行読み込む
          len = strlen(buf);
          if(len > 0 && buf[len-1]=='\n'){  //改行取り除き
            buf[len-1] = '\0';  //printf("buf= %s\n",buf);
            sscanf(buf, "%s \n %c", cdate, &mark);
          
            strcpy(AT[id].date,cdate);
            if (!strcmp(name, "Bob")){AT[id].bob=mark;}
            else if (!strcmp(name, "Alice")){AT[id].alice=mark;}
            else if (!strcmp(name, "Carol")){AT[id].carol=mark;}
            id++;
          }
        }
      }
  }
  count=id;
  id=1;

for (a=2; a <4 ; a++){
  if (fgets(buf,MAX,fp[2]) != NULL){
        len = strlen (buf);
        //printf("%s\n", buf);printf("%d\n", len);
      if(len>0 && (buf[len-1] == '\n')){
        buf[len-1] = '\0';
        sscanf( buf, "#%s", name); //個人を特定
        //printf("%s\n",name);
        while (fgets(buf,MAX,fp[2]) != NULL){ //一行読み込む
          len = strlen(buf);
          if(len > 0 && buf[len-1]=='\n'){  //改行取り除き
            buf[len-1] = '\0';  //printf("buf= %s\n",buf);
            sscanf(buf, "%s \n %c", cdate, &mark);
            for(id=1;id<=count;id++)
            if(!strcmp(AT[id].date,cdate)){
              if (!strcmp(name, "Bob")){AT[id].bob=mark;}
              else if (!strcmp(name, "Alice")){AT[id].alice=mark;}
              else if (!strcmp(name, "Carol")){AT[id].carol=mark;}
            }
            else {
              count++;
              id=count;
              strcpy(AT[id].date,cdate);
              if (!strcmp(name, "Bob")){AT[id].bob=mark;}
              else if (!strcmp(name, "Alice")){AT[id].alice=mark;}
              else if (!strcmp(name, "Carol")){AT[id].carol=mark;}
            }
          }
        }
      }
  }
}
 


  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------");
  for (id = 1; id < count; id++){
    n = atoi(AT[id].date);
    day = n % 100; month = (n / 100) % 100; year = n / 10000;
    printf("%4d / %2d / %2d \t %c \t %c \t %c \n",
      year, month, day, AT[id].alice, AT[id].bob, AT[id].carol);
  }
  printf("-------------------------------------");
  
  return 0;
}


