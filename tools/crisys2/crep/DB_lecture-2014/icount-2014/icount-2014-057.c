include <stdio.h>

int main()
{
  char str[100];
  int count,i,j;

  printf("数字列を入力して下さい: ");
  scanf("%s", str );

  count=0;
  for( j = 0; j <= 9; j++ ){
   for(i = 0; str[i] != '\0'; i++ ){
    if( str[i] = j ){
      count++;
    }
   }
   printf("%dは%d個含まれています.\n",j, count);
  }
   return 0;
}
