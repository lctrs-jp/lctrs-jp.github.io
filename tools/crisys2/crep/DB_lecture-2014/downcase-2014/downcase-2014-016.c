#include <stdio.h>
#include <string.h>

void downcase(char str[]); // 大文字を小文字に変換する関数

/* main()関数は変更しない */
int main(void)
{
  int i;
  char test[][2][40] = { /* 入力と正しい出力のペア*/
    {"STRING", "string"},
    {"string", "string"},
    {"CamelStyle", "camelstyle"},
    {"snake_style", "snake_style"},
    {"123aBc789", "123abc789"},
    {"!@#$%^&*XyZ(){}", "!@#$%^&*xyz(){}"},
    {"全角ＡＢＣａｂｃ", "全角ＡＢＣａｂｃ"}, // 全角文字は変更しない
    {"", ""},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };

  i = 0;
  while (strcmp(test[i][0],"***end***")){
    downcase(test[i][0]);
    if (!strcmp(test[i][0],test[i][1]))
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %s\n",test[i][0]);
      printf("  期待される結果  : %s\n",test[i][1]);
    }
    i++;
  }

  return 0;
}

/* 以下の関数を変更する */
void downcase(char str[])
{
  int i;
  switch (i){
  case 'A':
    printf("a");
    break;

  case 'B':
    printf("b");
    break;

  case 'C':
    printf("c");
    break;

  case 'D':
    printf("d");
    break;

   case 'E':
    printf("e");
    break;

  case 'F':
    printf("f");
    break;

  case 'G':
    printf("g");
    break;

  case 'H':
    printf("h");
    break;

  case 'I':
    printf("i");
    break;

  case 'J':
    printf("j");
    break;

  case 'K':
    printf("k");
    break;

  case 'L':
    printf("l");
    break;
 
  case 'M':
    printf("m");
    break;

  case 'N':
    printf("n");
    break;

  case 'O':
    printf("o");
    break;

  case 'P':
    printf("p");
    break;

  case 'Q':
    printf("q");
    break;

  case 'R':
    printf("r");
    break;

  case 'S':
    printf("s");
    break;


  case 'T':
    printf("t");
    break;

  case 'U':
    printf("u");
    break;

  case 'V':
    printf("v");
    break;

  case 'W':
    printf("w");
    break;

  case 'X':
    printf("x");
    break;

  case 'Y':
    printf("y");
    break;

  case 'Z':
    printf("z");
    break;

  default:
    printf("%c",i);
  }
    //文字列中の大文字を小文字に変換する関数
// ただし，変換するのは A から Z までのアルファベットだけで
// それ以外の文字・記号は変更しない

  return;
}
