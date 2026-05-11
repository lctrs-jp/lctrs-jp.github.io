#include<stdio.h>
int main()
{
  int p;
  printf("数字を入力してください。(２以上)");
  scanf("%d",&p);

  //見栄え重視のwhile
  while(p!=1){
    printf("%d ->",p);//初期値も書けるように
    if(p%2==0)
      p=p/2;
    else if(p%2==1){
      p=3*p+1;
    }}

  printf("1");//これもwhileに組み込みたかった。

  return 0;
}   
