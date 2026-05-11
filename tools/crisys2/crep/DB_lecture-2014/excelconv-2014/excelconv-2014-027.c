#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void)
{
  int i,a,sum=0;
  char str[7];

  printf("大文字を５文字以内で入力\n");
 
  fgets(str,7,stdin);
 
  a=strlen(str);
 
  for(i=0;str[i]!='\0';i++){
    sum=pow(26,a-i-1)*(str[i]-64)+sum;
  }

  printf("%d\n",sum);

  return 0;
}
