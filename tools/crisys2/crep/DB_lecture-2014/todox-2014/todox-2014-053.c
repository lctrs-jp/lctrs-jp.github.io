#include <stdio.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main()
{
  struct todo item = { 2014, 12, 10, 17, 0, "プログラミング課題提出" };
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
 item.day, item.hour, item.minute, item.content);
  return 0;
}

