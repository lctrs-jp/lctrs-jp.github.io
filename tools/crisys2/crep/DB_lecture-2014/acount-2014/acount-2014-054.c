#include <stdio.h>

//最も出現回数の多い文字を表示する
int main(void)
{
  int i, j, max , count[] ={0};
  char moji[];

  printf("文字を入力してください。（アルファベットのみ）:" );
  scanf("%s",  moji);//文字入力

  for( i = 0 ; i < strlen(moji) ; i++){//一文字ずつ見てく
    if(65 <= moji[i] && moji[i] <= 90 ){//大文字か小文字かで場合分け
      count[moji[i]-32] ++;//大文字を小文字に直してカウント
	}
    else if('a' <= moji[i] && moji[i] <= 'z'){
      cont[moji[i]-0] ++;//小文字をカウント
    }
  }

  for(j = 0 ; j < strlen(count); j++){
    if(count[j + 1] > count[j])//出現回数を比較
      max = count[j+1];//格納
      else 
	max = count[j]; 
  }



      printf("最も出現した文字は %s です。%d 回です。" , moji[j] , max);

  return 0;
}
