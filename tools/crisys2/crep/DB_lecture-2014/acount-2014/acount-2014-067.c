#include<stdio.h>
#include<string.h>

int main()
{
  char moji[101], saihin[60];
  int i, count;
  printf("文字列を入力してください(長さ100以下): ");
  fgets(moji, 101, stdin);


  for(i = 'A',strlen(moji),i++) 
	if(moji>='A' && moji<='Z' && moji>='a' && moji<='z')
     count++;



  printf("最頻出文字は %c\n", );
  printf("出現回数は %d回\n",count );

  return 0;
}
