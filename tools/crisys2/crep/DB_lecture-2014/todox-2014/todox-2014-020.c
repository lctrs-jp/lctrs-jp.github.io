#include <stdio.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc, char *argv[])
{
  int x, y, z;
  FILE *fp;

  sscanf(argv[1], "%d/%d/%d", &x, &y, &z);

  if ((fp = fopen("argv[2]", "r")) == NULL) {
    printf("ファイルを開くことができません\n");
  }

  return 0;
}
