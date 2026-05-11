#include <stdio.h>
#include <string.h>

int main(void)
{
  char mode, oldmode, stats[101];
  int  i, j, l;
  int count, oldcount;
  l = strlen(stats);

  printf("文字列を入力して下さい(長さ100以下): ");
  scanf("%s", &stats);

  oldcount = 0;
  count = 0;
  /* 最頻出文字を調べる */
  for (i = 0; i < l; i++) {
    mode = stats[i];

    /* この文字の出現回数を数える */
    for (j = 0; j < l; j++)
      if (mode == stats[j])
        count++;

    /* 以前の数より多ければ、新しいモードを使用する */
    if (count > oldcount) {
      oldmode = mode;
      oldcount = count;
    }
  }
  printf("最頻出文字は %s \n", oldmode);
  printf("出現回数は %d回 \n", oldcount);

  return 0;
}

