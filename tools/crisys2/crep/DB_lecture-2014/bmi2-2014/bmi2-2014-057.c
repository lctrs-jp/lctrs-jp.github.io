#include <stdio.h>

int main(void)
{
  double height,weight,bmi ;
  
  do{
    printf("身長を入力してください（m）");
    scanf("%lf", &height );
    if (height<=0)
      printf("不正な入力です\n");
  }while(height<=0);
    
  do{
    printf("体重を入力してください（kg）");
    scanf("%lf", &weight );
    if(weight<=0)
	 printf("不正な入力です\n");
  }while(weight<=0);

  bmi=weight/(height*height);
  printf("bmi");
  printf("%lf\n",bmi);
 
 if(bmi<18.5)
    printf("あなたはやせです\n");
 else if (bmi<25)
    printf("あなたは標準です\n");
 else if (bmi<30)
    printf("あなたは肥満です\n");
 else
    printf("あなたは高度肥満です\n");
 return 0;
}
