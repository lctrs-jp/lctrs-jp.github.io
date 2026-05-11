#include<stdio.h>

int main()
{
  char str[101];
  int i, j, m, max, sum[100] ;

  printf("アルファベット( 大文字、小文字 )を入力してください。( 100文字以下 )\n");
  fgets( str, 101, stdin );

  for( i == 0; i != 101; i++ ){
    sum[i] = 0;
  }

  for( j == 0; str[j] != '\0'; j++ ){
    if( (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z') ){
    for( i == 0; i != 101; i++){
    if( str[j] == i + 'a' ){
      sum[i] = sum[i] + 1;
      break;
    }else if( str[j] == i + 'A' ){
      sum[i] = sum[i] + 1;
      break;
    }
    }
    }
  } 

  max = 0;

  for( i == 1; i != 101; i++ ){
    if( sum[i] > sum[i-1] ){
      max = sum[i];
      m = i;
    }
  }

  if( j >= 'a' && j <= 'z' ){
  printf("%c の出現回数が最も多く%d 回出現した。", m + 'a', max );

  }else if( j >= 'A' && j <= 'Z' ){
    printf("%c の出現回数が最も多く %d 回出現した。", m + 'A', max );
  }

  return 0;
}
