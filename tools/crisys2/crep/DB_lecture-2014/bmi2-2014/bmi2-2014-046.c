#include <stdio.h>

int main()
{
  float n,y;
  printf("体重を入力してください。"); 
  scanf("%f",&n );
  printf("身長を入力してください。");
  scanf("%f",&y );
  
  if (n/(y*y) >=30) 

    printf("BMIは%fです。(高度肥満） ",n/(y*y));

  else if(n/(y*y) >=25)

    printf("BMIは%fです。（肥満）",n/(y*y));
  
  else if(25 >=n/(y*y),n/(y*y) >=18.5)
    printf("BMIは%fです。（標準）",n/(y*y));
  
  else
    printf("BMIは%fです。（やせ）",n/(y*y));


 return 0;
}
