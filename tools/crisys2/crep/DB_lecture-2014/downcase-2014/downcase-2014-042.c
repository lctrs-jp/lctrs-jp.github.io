#include <stdio.h>
#include <string.h>

void downcase(char str[]);

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

void downcase(char str[]){
	int i;
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
	}
	return;
}
