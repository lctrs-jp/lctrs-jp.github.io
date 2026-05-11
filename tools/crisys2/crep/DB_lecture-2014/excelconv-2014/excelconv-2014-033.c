#include<stdio.h>
#include<string.h>

int main(int argc,char *agrv[]) {
  //エラー用
  if (argc!=2) {
    printf("引数の個数が不適です\n");
    return 0;
  }

  int i,j,x,sl=strlen(agrv[1]),result=0; 

  for(i=0;i<sl;i++){
    if (*(agrv[1]+i)<'A' || *(agrv[1]+i)>'Z') {
      printf("文字不適です。A~Zから入力せよ\n");
      return 0;
    }
  }
  if (sl>5 || sl<=0) {
    printf("文字数不適です。1文字以上5文字以下で入力せよ\n");
    return 0;
    //ただし、このプログラムは文字数6文字以上であっても正常に動作する。
  }

  //メイン
  for(i=0;i<sl;i++){
    x=(*(agrv[1]+i)-'A'+1);
    for(j=0;j<sl-i-1;j++){
	x*=26;
    }
    result+=x;
  }
  printf("%d\n",result);
  return 0;
}
