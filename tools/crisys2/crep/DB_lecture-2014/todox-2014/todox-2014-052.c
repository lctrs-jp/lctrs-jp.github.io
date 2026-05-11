#include <stdio.h>
#include <string.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item;

void enter();//入力する関数

int main()
{
  char buf[100];
  void enter();

  sscanf(buf,"%4d/%2d/%2d %2d:%2d %s", &item.year, &item.month, &item.day, &item.hour, &item.minute, item.content);

  sprintf(buf,"%.4d/%.2d/%.2d %.2d:%.2d %s", &item.year, &item.month, &item.day, &item.hour, &item.minute, item.content);

  printf("%s\n", buf); 
  return 0;
}
void enter()
{
  int len = 0;
  char buf[100];

 
  /* 文字列が入力されるまで入力を要求 */
  while( len <= 0 ){
    printf("Input\n ");
    fgets( buf, 100, stdin );
    /* 末尾の改行記号を除去 */
    if( (len = strlen(buf)) > 0 && buf[len-1] == '\n' ){
      len --;
      buf[len] = '\0';
    }
    /* 何も入力されていなければやり直させる */
    if( len <= 0 )
      printf("No date\n");
    sscanf(buf,"%4d/%2d/%2d %2d:%2d %s", &item.year, &item.month, &item.day, &item.hour,&item.minute, item.content); 
 }


  return;
}
