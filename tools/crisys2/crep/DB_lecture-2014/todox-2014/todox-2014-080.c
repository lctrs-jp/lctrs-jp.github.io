#include <stdio.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[100];
};
int main()
{
  struct todo item = {2014/09/09 18:00 履修登録
		      2014/12/10 17:00 プログラミング課題提出
		      2014/12/24 13:00 レポート提出
		      2014/10/08 24:00 履修科目の確認
		      2014/12/11 08:45 プログラミング中間試験対策
		      2015/01/29 08:45 プログラミング期末試験対策
		      2014/12/03 17:00 プログラミング課題提出
		      2014/11/04 12:00 レポート提出
		      2014/12/24 17:00 プログラミング課題提出
  }
  while( fgets(buf,100,fp) != NULL ){
    sscanf(buf,"%d:%d:%d", &nyear, &nmonth, &nday );
    if(nyear<year&&nmonth<month&&nday<day)
      printf("%4d/
