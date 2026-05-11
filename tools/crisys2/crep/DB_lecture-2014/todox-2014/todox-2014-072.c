#include <stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
  struct todo item[100];
  int x, y, z = 0, n, date, time, len;
  FILE *fp;
  char *out[100], buf[256];

  if(argc<2){//起動時引数の存在を確認
    printf("確認: %s 名前1 ... 名前2\n", argv[0]);
    exit(1);
  }



  for( x = 0; x < z; x++)
    printf("%4d/%2d/%2d %2d:%.2d %s\n",
           item[x].year, item[x].month, item[x].day,item[x].hour,
           item[x].minute, item[x].content);
  return 0;
}

for ( x = 1; x < argc ; x++ ){// 起動時引数のファイルを順に処理
  if((fp =fopen(argv[x],"r")) ==NULL){
    fprintf(stderr,"エラー: オープンに失敗しました→ \"%s\".\n",argv[x]);
    exit(1);
  }
  while(fgets(buf, 256, fp) !=NULL){//予定を1行ずつ読み込み、個数をzでカウントしながら配列に格納
  len = strlen(buf);
 if (len>0 && buf[len-1] == '\n' ) buf[len-1] = '\0';//末尾の改行記号を除去
  n = split(buf, out);//年月日、時間、内容に分割
 if (n==0)continue;
 else if (n<3)fprintf(stderr, "エラー(%s): %s\n", argv[x], buf);//3分割できない場合、エラー
 else{
   date = atoi(out[0]);//年月日を計算して格納
   item[z].year = date/10000;
   item[z].month = (date % 10000)/100;
   item[z].day = (date % 100);
   time = atoi(out[1]);//時分を計算して格納
   item[z].hour = time/100;
   item[z].minute = time % 100;
   strncpy(item[z].content, out[2],256);//内容をコピー
   z++;
 }
  }
  fclose(fp);
 }
