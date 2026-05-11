#include<stdio.h>
#include<string.h>
#include<math.h>

int excel(char a[]);

int main()
{
  char a[5];
  printf("文字列を入力してください(5文字以下)");
  gets(a);
  printf("%s=%d\n",a,excel(a));
  return 0;
}

int excel(char a[]){
  int n;
   
  n = pow(26,strlen(a)-1)*(*a-64); 
   
  if(*a != 0){
    a++;
    return n + excel(a) ;
  }
    else
      return 0;
  }

  
