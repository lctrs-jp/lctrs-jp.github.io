#include <stdio.h>
#include <string.h>


int main(void)
{
  char str1[101], str2[26];//str1は入力された文字列を保持、str2はアルファベットに対応
  int i, j, k, l, m,  max = 0, str3[26];//str3はアルファベットの数を保持

  for (i = 0; i < 26; i++) {
    str2[i] = 'a' + i;
    str3[i] = 0;
  }//str2とstr3の初期化
  printf("文字列を入力してください(長さ100以下) : ");
  fgets(str1, 101, stdin);

  //以下でそれぞれの数を測定
  for (j = 0; j < 26; j++) {
    for (k =0; k< 101; k++)
      if (str1[k] == str2[j] || str1[k] == str2[j] - ('a' - 'A'))
	str3[j]++;
  }

  //以下で最大値を確かめる
  for (l = 0; l < 26; l++)
    if (max < str3[l])
      max = str3[l];

  //結果を出力
  printf("最頻出文字は ");
  for (m = 0; m < 26; m++) {
    if (str3[m] == max)
	printf("%c ", str2[m]);
  }
  printf("\n出現回数は %d \n", max);
	
  return ;
}




  
