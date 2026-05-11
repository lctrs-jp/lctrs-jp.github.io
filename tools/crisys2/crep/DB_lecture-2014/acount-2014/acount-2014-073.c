#include <stdio.h>
#include <string.h>

int main (void)
{
  int i,t,j;
  char num;
  char str[101];
  int count[26];            //countには文字の個数をいれる　前からa b c ,,,
  for (i = 0; i <27; i++){
    count[i] = 0;
  }
  printf("\n文字列を入力してください。（長さ100以下）：");
  scanf("%s",str);
  
  for (i = 0; i < strlen(str); i++){     //一文字ずつチェックしていく
    //文字からa(A)を引いて0～25の数字と対応させる 
    if (str[i] >= 'A' && str[i] <= 'Z'){       //もし大文字なら
      num = str[i] - 'A';
      j = 1;   
    }else if(str[i] >= 'a' && str[i] <= 'z'){  //もし小文字なら
      num = str[i] - 'a';
      j = 1;           
    }else 
      j = 0;
    if (j){                       //jを使って文字がa～zかA～Zの場合だけ数えるようにする
      for (t = 0; t < 26; t++){
	if ( t == num)          
	  count[t]++;                
      }    
    }
  }
  
  t = 0;
  
  for (i = 0; i < 26; i++){      //一番多い出現数を調べる
    if (t < count[i])
      t = count[i];
  }
  printf("最頻出文字は ");
  for (i = 0; i < 26; i++){        //出現回数が一番多い文字を調べる
    if (t == count[i]){
      printf("%c ",i +'a');        //文字として表示するときは'a'を足す
      
    }
  }
  printf("\n出現回数は %d回\n",t);   //最多出現回数を表示する
  
  return 0;
}
