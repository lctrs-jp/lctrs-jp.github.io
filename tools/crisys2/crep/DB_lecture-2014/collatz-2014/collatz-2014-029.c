#include<stdio.h>

int main()

{

  int num;

  printf("数字を入力してください(2以上3x253 以下の整数):" );
  scanf("%d" , &num);


  while(num!=1)/*最終結果が1であることは自明であるため*/{
      if(num % 2 ==0){
	num=num/2;}
      else if(num % 2 !=0){
	num = num*3 +1;}
      printf("%d--" , num);/*途中経過の表示*/

    }
  printf("\n");
    printf("%d\n",num);
    
      return 0;
}
