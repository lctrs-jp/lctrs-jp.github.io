#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define LEN 273

struct attendance{
  char date[9]; //日付
  char alice; //Aliceの予定
  char bob; //Bobの予定
  char carol; //Carolの予定
  int ok;
  int unfixed;
};

int load(struct attendance d[MAX],char *filename,int size);//プロトタイプ宣言
void print(struct attendance d[MAX],int size);

int main(int argc, char *argv[]){

  struct attendance item[MAX];
  int i,size;

  if(argc < 2){
    printf("Usage: %s filename1 ... filename2\n", argv[0]);
    exit(1);
  }

  for(i = 1;i < argc;i++){ //読み込み
    size = load(item,argv[i],size);
  }
  printf("date\tAlice\tBob\tCarol\n");
  printf("-----------------------------\n");
  print(item,size);  //自分で作成した関数
  printf("----------------------------\n");
  int k,j;
  for(k = 0;k < size;k++){
    j = atoi(d[i].date);
    printf("%4d/%2d/%2d\t[ok:%d, ?:%d]\n",
	   j / 10000, (j/100) % 100, j % 100, item[k].ok, item[k].unfixed) 
      }
  printf("----------------------------\n");
      return 0;
}

int load(struct attendance d[MAX],char *filename,int size){
  FILE *fp;
  char buf[LEN];
  int len, i;
  char ok[LEN],date[9],name[LEN];

  if((fp = fopen(filename,"r")) == NULL){
    printf("ファイル %s のオープンに失敗", filename);
    exit(1);
  }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if(len > 0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  sscanf(buf,"#%s",name); //誰の予定か確認。

  while(fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf,"%s %s", date, ok); //表の日付と参加を読み取る。

    for(i=0;i<size;i++){
      if(strcmp(date,d[i].date) == 0){//その日付も持つ構造体があるか確認。
	if(*name == 'Alice') //nameから誰の予定に入れるかを判断。
	  d[i].alice = ok;
	else if(*name == 'Bob')
	  d[i].bob = ok;
	else if(*name == 'Carol')
	  d[i].carol = ok;
	if(ok == 'o') //参加の数をカウント
	  d[i] += 1; 
	else if(ok == '?') // 未定をカウント 
	  d[i] += 1;
	break;
      }
    }

    if(i == size){ //新たな日付を持つ構造体を用意。
      if(*name == 'Alice') //nameに応じた構造体に予定(ok)を収納。
	strcpy(d[i].alice, ok);
      else if(*name == 'Bob')
	strcpy(d[i].bob, ok);
      else if(*name == 'Carol')
        strcpy(d[i].carol, ok);
    }
    size++; //構造体の数をカウント
  }
  return size;
}

void print(struct attendance d[MAX],int size)
{
  int i,j;
  for(i = 0;i < size;i++){
    j = atoi(d[i].date); //dateを数字として扱い、年、月、日付に分ける。
    printf("%4d/%2d/%2d\t%s\t%s\t%s\n",
           j / 10000, (j/100) % 100, j % 100, d[i].alice, d[i].bob, d[i].carol);
  }
}
