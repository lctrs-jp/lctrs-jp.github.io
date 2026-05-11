#include <stdio.h>

int main()
{
  int n;

  printf("数字を入力してください\n");
  scanf("%d", &n);

    for(; n == 1 ;)
      {
	if(n%2 == 0)
	  {
 	  n = n/2;
	  printf("%d \n",n/2);
          }else{
          n = 3n+1;
	  printf("%d",3n+1);
	}}
  return 0;
}
