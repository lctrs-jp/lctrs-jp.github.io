#include<stdio.h>
#include<string.h>
int chr_cnt(char k, char a[100]);

int main(void)
{
  char k, d, a[100];
  int item[26], a, b, count, t, j;
    printf("文字列を入力してください（長さ100文字以内）: ");
    fgets(a, 100, stdin);
    j = 0;
    for(k = 65; k < 90; k++){
      item[j] = chr_cnt(k, a);
  j++;
    }

    for (a = 1; a < count; ++a)
      for (b = count - 1; b >= a; --b){
	if(item[j - 1] > item[j]){
	  t = item[j - 1];
	  item[j - 1] = item[j];
	  item[j] = t;
	}
      }
    printf("もっとも多い文字は %c で %dこ含まれています。\n", j, item[0]);
    for(j = 0; j < 26; j++)
      if item[0] == chr_cnt(j, a)
    printf("もっとも多い文字は %c で %d個含まれています。\n", j, item[0]); 
    return 0;
}

int chr_cnt(char k , char scr[100])
{
  int j, l;
  j = 0;
      for(l = 0; scr[l] != '\0'; l++)
	if(scr[l] == k) /* !～~までの記号文字をカウントする */
	  j++;/* 等しいときに出力値を1つ増やす */
	else if(scr[l] == k + 32)
	  j++;
  return j;   
}
