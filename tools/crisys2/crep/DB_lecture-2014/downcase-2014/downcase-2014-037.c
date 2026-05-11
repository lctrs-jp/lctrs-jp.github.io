#include<stdio.h>

void downcase(char str[]);

int main()
{
  char str[50];
    printf("数かアルファベットを入力してください");
  fgets(str,50,stdin);

  downcase(str);

  printf("%s\n",str);
   
   return 0;
}

void downcase(char str[])
{
  int i;
  for(i=0;i<50;i++){
    if(str[i]>=65&&str[i]<=99)
    str[i]=  str[i]-'A'+'a';
	}
  return ;
}

