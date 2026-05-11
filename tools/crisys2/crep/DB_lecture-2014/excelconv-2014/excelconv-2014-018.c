#include <stdio.h>

/*Excel文字列変換*/
int trans(char *buf, int i);

int main(int argc, char *argv[])
{
  int len; 

   /* 条件に合わない場合は計算しない*/
  if(argc == 1){ /* 引数が無い場合*/
    printf("AからZZZZZを引数で与えてください\n");
    return 0;
  }
  for(len = 0; (*(argv[1] + len)) != '\0'; len++){ /* AからZ以外が引数*/
    if((*(argv[1]+len) < 'A') || (*(argv[1]+len) >'Z')){
      printf("AからZZZZZを引数で与えてください\n");
      printf("%d",len);
      return 0;
    }
  }
  if(len > 5){ /* 引数が5文字より多い*/
    printf("引数は5文字以内です\n");
    return 0;
  }

   /* 計算して結果を表示*/
  printf("%s -> %d\n", argv[1], trans(argv[1], len));

  return 0;
}

 /* Excelの列を数値変換して返す関数*/
int trans(char *buf, int i) /* bufは文字列、iは文字列の長さを受け取る*/
{
   if(i == 0)
    return 0;
  else
    return (*(buf + i-1) - 'A' + 1) + (26 * (trans(buf, i - 1)));
}
