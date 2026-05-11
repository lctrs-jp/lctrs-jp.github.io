#include<stdio.h>

int main()
{
  int a=0,b,cnt[27];
  for(b=0;b<27;b++)
    cnt[b]=0; 
  char str[101];

  printf("文字列を入力してください(長さ100以下):");
  fgets(str,101,stdin);

  for(a=0;str[a]!='\0';a++)
    { if(str[a]<=90&&str[a]>=65)
     


 cnt[str[a]-65]++;
    }



  for(a=0;a<27;a++)
  printf("%d",cnt[a]);
	return 0;
}
