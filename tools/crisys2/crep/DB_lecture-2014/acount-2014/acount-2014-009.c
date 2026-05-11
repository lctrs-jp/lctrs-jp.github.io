#include <stdio.h>

int main()
{
  char buf[101];
  int i,j, cnt[27];
  for(j=0 ; j<27 ;j++);

  printf("文字列を入力:");
  fgets(buf, 101,stdin);

  for (i=0 ;buf[i] != '\0' ; i++)
    if( 'a' <=buf[i] && buf[i] <= 'z')
      cnt[buf[i]-'a'] ++;
  for(i= 0 ; i<27 ;i++)
    printf("%dは%d個含まれている\n",i,cnt[i]);

  return 0;
}
