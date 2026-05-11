#include<stdio.h>

int main()
{
  char str[101];
  char omoji[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char komoji[] = "abcdefghijklmnopqrstuvwxyz";
  int i, j, maxnum, cnt[26], max;

  for(i = 0;i < 26;i++)
    cnt[i] = 0;

  printf("最頻出文字およびその出現回数を表示します。\n");
  printf("文字列を入力してください。(長さ100以下)\n");
  fgets(str,101,stdin);

  for(i = 0;str[i] != '\0';i++)
    for(j = 0;j < 26;j++)
      if(str[i] == omoji[j] || str[i] == komoji[j])
        cnt[j]++;

  maxnum = 0;
  max = 0;
  for(i = 0;i < 26;i++)
    if(cnt[i] > maxnum){
      maxnum = cnt[i];
      max = i;
    }
  printf("最頻出文字は%s(%s)で、出現回数は%d回。\n",omoji[i],komoji[i],maxnum);

  return 0;
} 
