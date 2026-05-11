#include<stdio.h>
#include<string.h>

int main()
{
  char str[100];
  int count[26];
  int i,j,t,k;

  printf("文字列を入力してください\n");
  gets(str);

  for( j = 0; j < 26; j++){
    count[j] = 0;
    k = j + 65;
    t = j + 97;
    for( i = 0; str[i] != '\0'; i++){
    if( str[i] == k)
      count[j] = count[j] + 1;
    if( str[i] == t)
      count[j] = count[j] + 1;
    printf("%sは%d個含まれています\n",str[k],count[j]);
    
    }
  }
  
  //バブルソートを使用
  for( j = 1; j < 26; j++){
    if(count[j-1] > count[j])
      t = count[j-1];
      count[j-1] = count[j];
      count[j] = t;
  }
  
  printf("%d",count[25]);
  return 0;
}
