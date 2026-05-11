#include<stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int i, x, y, z, a, b;
  char str[80];
  char *p, c;
  for (i = 0; i < 7; i++) 
    str[0] = "2014, 09, 09, 18, 00, 履修登録";
      str[1] ="2014, 12, 10, 17, 00, プログラミング課題提出\n ";
      str[2] = "2014, 12, 24, 13, 00, レポート提出\n ";
      str[3] = "2014, 10, 08, 24, 00, 履修科目の確認\n";
      str[4] = "2014, 12, 11, 08, 45, プログラミング中間試験対策\n ";
      str[5] = "2015, 01, 29, 08, 45, プログラミング期末試験対策\n"; 
      str[6] = "2014, 12, 03, 17, 00, プログラミング課題提出\n ";
 
  if((fp = fopen("mytodo", "w")) == NULL)
    {
      printf("can't open the FILE\n"); 
      exit(1);
    }
  p = str;
  while(*p)
    {
      if (fputc(*p, fp) == EOF)
	{
	  printf(" can't put content the FILE\n");
	  exit(1);
	}
      p++;
    }
struct todo 
{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[100];
};

int main()
{
  struct todo item = {
    sscanf(str,"%4d/&2d/%2d/%2d:%.2d %s/n", &x, &y, &z, &a, &b, &c);
  printf("%4d/%2d/%2d/%2d:%.2d %s/n", item.year, item.month, item.day, item.hour, item.minute, item.content );
    fclose(fp); 
    return 0;
}
};
}
