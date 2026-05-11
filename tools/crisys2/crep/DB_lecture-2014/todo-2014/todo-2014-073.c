#include <stdio.h>
#include <stdlib.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc, char *argv[])
{
  FILE *fp;
  char ch;

  /* コマンドライン引数の値が正しいか調べる */
  if (argc != 5){
    printf("使用法: <プログラム名> <年> <月> <日> <ファイル名>\n");
    exit(1);
  }

  /* ファイルを開く */
  if ((fp = fopen(argv[4], "r")) == NULL) {
    printf("ファイルを開くことができません\n");
    exit(1);
  }

  /* x,y,zに年月日を取り出す */
  int x,y,z; char buf[] = "todo.year/todo.month/todo.day";
  sscanf(buf, "%d/%d/%d", &x, &y, &z);

  if(x >= argv[1] && y >= argv[2] && z >= arg[3]){
    for(;;){
      if((ch = fgetc(fp)) == EOF)
	break;
      putchar(ch);
    }
  }
  fclose(fp);

  return 0;
}
