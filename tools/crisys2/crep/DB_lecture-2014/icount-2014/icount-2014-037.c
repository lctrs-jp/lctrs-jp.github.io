#include <stdio.h>
#include <string.h>

int main(void)
{
  char num[100];
  int i, t;
  int count[10]={0,0,0,0,0,0,0,0,0,0};
  int l;
  l = strlen(num); 

  printf(" 数字列を入力してください(長さ100以下): ");
  scanf("%s", &num);
  for( i = 0; i < 100; i++){ 
    if(num[i] == '0')
      count[0]++;
    if(num[i] == '1')
      count[1]++;
    if(num[i] == '2')
      count[2]++;
    if(num[i] == '3')
      count[3]++;
    if(num[i] == '4')
      count[4]++;
    if(num[i] == '5')
      count[5]++;
    if(num[i] == '6')
      count[6]++;
    if(num[i] == '7')
      count[7]++;
    if(num[i] == '8')
      count[8]++;
    if(num[i] == '9')
      count[9]++;
  }
  for( t = 0; t < 10; t++)
    printf(" %d は %d 個含まれています\n", t, count[t]);

  return 0;
}
