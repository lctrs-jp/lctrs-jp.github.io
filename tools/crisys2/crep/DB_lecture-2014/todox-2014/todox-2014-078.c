#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//仕事データを表す構造体をevent型に変更
typedef struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}todo;

todo item[100]; //予定のデータのリストを保持する配列
int count = 0; //データの個数
char *d; //引数で指定された日時

void load(FILE *fp);
void display(void);
int split(char buf[], char *out[]); //文字列を空白で分割する関数

int main(int argc, char *argv[])
{
  FILE *fp;
  int i;
  
  //一つも引数がない場合
  if (argc <= 1){
    printf("年月日とファイルを指定してください\n");
    exit(1);
  }
  else {
    if ((fp = fopen(argv[2],"r")) == NULL){
      printf("エラー：ファイル(%s)を開けません\n",argv[2]);
      exit(1);
    }

    d = argv[1];

    load(fp);

    fclose(fp);

  }

  display();

  return 0;
}

 
void load(FILE *fp)
{
  int i,len;
  char buf[100], *out[100];
  
  //データを読み込む
  while (fgets(buf, 100, fp) != NULL){
    //改行文字を取り除く
    if( (len = strlen(buf)) > 0 && buf[len-1] == '\n' ){
      buf[len -1] = '\0';
    }
    
    //年月日、時間、内容を分割
    i = split(buf,out);

    if (i == 3){
      //年、月、日、時間、内容を格納したい場所にコピー
      sscanf(out[0], "%d/%d/%d", &item[count].year, &item[count].month, &item[count].day);
      sscanf(out[1], "%d:%d",&item[count].hour, &item[count].minute);
      strcpy(item[count].content,out[2]);
      count++;
    }

    if (count >= 100){
      printf("容量制限を超えています\n");
      exit(1);
    }

  }

  return;

}


void display(void)
{
  int i,year,month,day,date,date2;


  //データがない場合
  if (count < 1){
    printf("データがありません\n");
    return;
  }

  sscanf(d,"%d/%d/%d", &year, &month, &day);

  date = year * 10000 + month * 100 + day;//起動時引数の比較対象を作る
  
  for (i = 0; i < count; i++){
 
   date2 = item[i].year * 10000 + item[i].month * 100 + item[i].day;

    if (date <= date2)
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n",
	     item[i].year,
	     item[i].month,
	     item[i].day,
	     item[i].hour,
	     item[i].minute,
	     item[i].content);
    
  }
  
  return;    
  
}



int split(char buf[], char *out[]){

  int n = 0;                //nは分割数

  while (*buf){           //文字列の終端まで繰り返す
    for (;*buf == ' ';buf++);          //まずはスペースがあれば飛ばす

    if (*buf != '\0'){
      *out++ = buf;              //out[]にbuf(アドレス)をいれる　
      n++;                //分割数を加算
    }

    for (;*buf != ' ' && *buf != '\0';buf++);     //次にスペースかヌルにあたるまでアドレスを移動
    
    if (*buf ==' ')            //もしスペースに当たったらそこで文字を区切る
      *buf++ = '\0';
    
  }
  
  return n;
}
