#include <stdio.h>
#include <string.h>

char rate(char str[]);
int count(char str[]);

int main(void)
{
  char str[101];
  printf("文字列を入力して下さい(長さ100以下) : ");
  fgets(str, 101, stdin);

  printf("最頻出文字は %c\n", rate(str));
  printf("出現回数は %d 回\n", count(str));

  return 0;
}

int count(char str[])
{
  int i, j, k, l, c[27], d[27], max, m, sum[27];

  for(l = 0; l < 27; l++)
    c[l] = 0;

  for(i = 0; str[i] != '\0'; i++)
    for(k = 65; k < 123; k++){
      if((str[i] > 64) && (str[i] < 91)){
        if(str[i] == k)
          c[k-65]++;
        else
          if((str[i] > 96) && (str[i] < 123))
  	    if(str[i] == k)
	      c[k-97]++;
      }
    }

  max = 0;
  for(j = 0; j < 26; j++)
    if(max < c[j])
      max = c[j];

  return max;
}

char rate(char str[])
{
  int i, j, k, l, c[27], d[27], max, m, sum[27];
  char chart;

  for(l = 0; l < 27; l++)
    c[l] = 0;

  for(i = 0; str[i] != '\0'; i++)
    for(k = 64; k < 123; k++)
      if(str[i] == k){
	if((str[i] > 64) && (str[i] < 91))
	  c[k-65]++;
	else
          if((str[i] > 96) && (str[i] < 123))
	    c[k-97]++;
      }

  max = 0;
  for(j = 0; j < 26; j++)
    if(max < c[j]){
      max = c[j];
      chart = j + 97;
    }

  return chart;
}
