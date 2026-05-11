#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mystrcat(char *i1, char *i2); 

int main(void)
{
  int x;
  char out[80];
  char test[][10][40] = {
    {"abcdef", "abc", "def"},
    {"abc", "", "abc"},
    {"abc", "abc", ""},
    {"", "", ""},
    {"***end***", ""}
  };

  for(x = 0; strcmp(test[x][0],"***end***"); x++){
    strcpy(out,test[x][1]);
    mystrcat(out,test[x][2]);
    if(strcmp(out,test[x][0])==0){
      printf("テスト%dは成功\n", x+1);
    }
    else{
      printf("テスト%dは失敗\n", x+1);
      printf("作った関数の結果: %s\n",out);
      printf("期待される結果: %s\n",test[x][0]);
    } 
  }
    return 0;
}
  void mystrcat(char *i1, char *i2){

    int x = 0;

    for(;*i1;i1++);

    while(*i2)
      *i1++ = *i2++;
    *i1 = '\0';
   
    return ;
  }
