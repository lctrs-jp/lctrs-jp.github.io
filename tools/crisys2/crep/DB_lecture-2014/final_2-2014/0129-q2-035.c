#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30//予定元の日数
#define NOP 3//人数
#define LENMAX 256//読み込み一行の最大。
typedef struct attendance {
  char date[9]; // 日にち 文字列型
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
} ATT;

ATT item[MAX];//予定を格納する配列


int load(char*filename,int size);
void printlist(void);

int main(int argc ,char *argv[]) {
  //引数チェック
  if (argc!=(1+NOP)) {
    printf("引数個数不適です\n");
    exit(1);
  }

  int i,size;
  for(i=0;i<argc;i++) {
    size=load(argv[i],size);
  }

  printlist();


  /*
  struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  int n, year, month, day;

  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol,
	 item.ok, item.unfixed );
  */
  return 0;
}


int load(char*filename,int size) {
  FILE *fp;
  char buf[LENMAX];
  char name[LENMAX];
  int id,i,j,k;

  for(i=0;i<NOP;i++) {
    //読み込み
    if ((fp=fopen(filename,"r"))==NULL) {
      printf("%s 読み込みに失敗しました\n",filename);
      exit(1);
    }
    j=0;
    while(fgets(buf,LENMAX,fp)!=NULL){
      //       printf("[(%d)%s]",j,buf);
      //改行コード削除
      if (buf[strlen(buf)-1]=='\n' && strlen(buf)>0) {
	buf[strlen(buf)-1]='\0';
      }

      //      if (strncmp(buf,"ELF",LENMAX)==0) { continue; };

      if (j==0) {
	//名前読み込み
	strcpy(name,buf);
	//名前が適当でないならば弾く
	id=0;
	if (strncmp(name,"#Alice",LENMAX)==0) {
	    id=1;
	    j=1;
	  } else {
	  if (strncmp(name,"#Bob",LENMAX)==0) {
	      id=2;
	      j=1;
	    } else {
	    if (strncmp(name,"#Carol",LENMAX)==0) {
		id=3;
		j=1;
	      } else {
		printf("%s は対応していません\n",name);
		//exit(1);
		break;
	      }
	    }
	}
      } else {
	char data1[LENMAX]="\0";
	char data2='\0';
	if (id) {
	  sscanf(buf,"%s %c",&data1,&data2);
	  //printf("%s %c\n",data1,data2);
	}
	for(k=0;k<size;k++){
	  //日程読み込み
	  if (strncmp(data1,item[k].date,LENMAX)==0) {
	    //一致する日程があった。
	    if (id=1) {
	      item[size].alice=data2;
	    }
	    if (id=2) {
	      item[size].bob=data2;
	    }
	    if (id=3) {
	      item[size].carol=data2;
	    }
	    break;
	  }
	}
	if (k==size){
	  //新規作成
	  strcpy(item[size].date,data1);
	  if (id=1) {
	    item[size].alice=data2;
	  }
	  if (id=2) {
	    item[size].bob=data2;
	  }
	  if (id=3) {
	    item[size].carol=data2;
	  }
	  size+=1;
	}
      }
    }
    fclose(fp);
  }
  return size;
}

void printlist(void) {
  int i;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-----------------------------\n");
  for(i=0;i<MAX;i++) {
    if (strlen(item[i].date)>0) {
      int n, year, month, day;
      sscanf( item[i].date, "%d", &n );
      day = n % 100;
      month = (n / 100) % 100;
      year = n / 10000;
      
      printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	     year, month, day,
	     item[i].alice, item[i].bob, item[i].carol);//,item.ok, item.unfixed );
    }
  }
  printf("-----------------------------\n");
  return;
}
