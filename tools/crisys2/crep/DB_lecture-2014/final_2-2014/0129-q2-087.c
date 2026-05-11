#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTEND;
//ATTEND item[30];
int load(ATTEND item[30], char *filename, int size);
int main(int argc, char *argv[])
{
  // struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  ATTEND item[30];
  int i, size;
  int n, year, month, day;
  for(i  = 0; i < 30; i++){
    item[i].ok = 0;
    item[i].unfixed = 0;
  }
  for(i = 1; i < argc; i++){
    size = load(item, argv[i], size);
  }
 
  printf("date\t\tAlice\tBob\tCarol\n");
  for(i = 0; i < size; i++){
  sscanf( item[i].date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;
  
  //  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item[i].alice, item[i].bob, item[i].carol,
	 item[i].ok, item[i].unfixed );
  }
  return 0;
}

int load(ATTEND item[30], char *filename, int size){
  FILE *fp;
  char buf[300], name[100], check, date[100];
  int len, time, i;
  if  ((fp = fopen (filename, "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました", filename);
    exit (1);
  }
  fgets(buf,300,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(name, &buf[1]);
  size = 0;
  while (fgets(buf,300,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%s %c", date, &check);
    for (i = 0;i < size;i++){
      if (strcmp(item[i].date, date)== 0){
	time = i;
	//	item[i].ok = 0;
	//	item[i].unfixed = 0;
      break;}
    }
    if(i == size){
      strcpy(item[i].date, date);
      time = size;
      size++;
      //    item[time].ok = 0;
      //  item[time].unfixed = 0;
    }
  
  
    if(strcmp(name, "Alice")  == 0){
      if(check - 'o' == 0){
	item[time].alice =  'o';
	item[time].ok++;
      }
    
      else if(check - '?' == 0   )      {
	item[time].alice = '?';
	item[time].unfixed++;
      }/*
	 else if(check = '?'){
	 item[time].alice = '?';
	 item[time].unfixed++;
	 }*/
      if(check - 'x' == 0){
	item[time].alice ='x';
      }/*
	 else if(check = 'x'){
	 item[time].alice = 'x';
	 }*/
    }
    
    if(strcmp(name, "Bob")  == 0){
      if(check - 'o' == 0){
      item[time].bob ='o';
        item[time].ok++;
      }

      else if(check - '?' == 0){
       item[time].bob ='?';
        item[time].unfixed++;
      }/*
         else if(check = '?'){
         item[time].alice = '?';
         item[time].unfixed++;
         }*/
      if(check - 'x' == 0){
       item[time].bob ='x';
      }/*
         else if(check = 'x'){
         item[time].alice = 'x';
         check - 'o' == 0}*/
    }
    if(strcmp(name, "Carol")  == 0){
      if(check - 'o' == 0){
	item[time].carol ='o';
        item[time].ok++;
      }

      else if(check - '?' == 0){
	item[time].carol ='?';
        item[time].unfixed++;
      }/*
         else if(check = '?'){
         item[time].alice = '?';
         item[time].unfixed++;
         }*/
      if(check - 'x' == 0){
	item[time].carol ='x';
      }/*
         else if(check = 'x'){
         item[time].alice = 'x';
         }*/
    }

      
      
      /*      
      
    if(strcmp(name, 'Bob') == 0){
	  if(check = 'o'){
	    item[time].bob = 'o';
	    item[time].ok++;
	  }
	  else if(check = '?'){
	    item[time].bob = '?';
	    item[time].unfixed++;
	  }
	  else if(check = 'x'){
	    item[time].bob = 'x';
	  }
	}
    if(strcmp(name, 'Carol') == 0){
      if(check = 'o'){
	      item[time].carol = 'o';
	      item[time].ok++;
      }
      else if(check = '?'){
	item[time].carol = '?';
	item[time].unfixed++;
      }
      else if(check = 'x'){
	item[time].carol = 'x';
	}
      */
   
  }   
  return size;
}	  
	
   
