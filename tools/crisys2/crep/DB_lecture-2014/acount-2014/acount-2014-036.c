#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[256];
  int a, b, i, t, s, count[26], number[26]; 

  for(i = 0; i < 26; i++)
    count[i] = 0;

 
  printf("アルファベットで何か書いてください。\n");
  scanf("%s", str);

  for(a = 0; a < strlen(str); a++){
    if(str[a] < 123 && str[a] > 96){
      count[str[a] - 97] = count[str[a] - 97] +1;
      number[a] = a;
    }
    else if(str[a] < 91 && str[a] > 64){
      count[str[a] - 65] = count[str[a] - 65] + 1;
      number[a] = a;
    }
  }

  for( a = 1; a < 26; ++a)
    for( b = 26 - 25; b >= a; --b){
      if(count[b - 1] > count[b]){
	t = count[b - 1];
	count[b - 1] = count[b];
	count[b] = t;

	s = number[b - 1];
	number[b - 1] = number[b];
	number[b] = s;
      }
    }
  printf("最大頻出数は %d 回です。\n", count[25]);

  for(b = 25; b > 0; b--){
    if(number[b] != number[b - 1]){
      printf("最大頻出文字は %c です\n", number[b] + 65);
      break;
    }
    else 
      printf("最大頻出文字は %c です\n", number[b] + 65);
  }
    return 0;
}
