#include <stdio.h>

int main(void)
{
  int len,i,max=0;
  char str[256];
  int cnt[26];

  for(i=0;i<=25;i++)
  {
    cnt[i]=0;
  }

  printf("文字列を入力してください（最大２５５文字）");
  fgets(str,256,stdin);
  for(len=0;str[len]!=0;len++);

  for(i=0;i<=len;i++)
  {
    if(str[i]>='A' && str[i]<='Z')
      cnt[str[i]-'A']++;
    if(str[i]>='a'&&str[i]<='z')
      cnt[str[i]-'a']++;
  }

  for(i=0;i<=25;i++)
  {
    if(max<=cnt[i])
      max=cnt[i];
  }

  printf("最頻出文字: ");
  for(i=0;i<=25;i++)
  {
    if(cnt[i]==max)
      printf("%c ",i+'a');
  }
  printf("\n回数 %d\n",max);

  return 0;
}
