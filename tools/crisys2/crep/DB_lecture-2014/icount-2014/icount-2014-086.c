#include <stdio.h>
#include <string.h>


int main(void)
{
  int i,j;
  char str[100];
  int kazu[10] = {0,0,0,0,0,0,0,0,0,0};

  printf("数字列を入力して下さい（長さ100以下）: ");
  scanf("%s", str);
  

  for(i = 0; i < strlen(str); i++){

   

    for(j = 0; j < 10; j++){

      if(j + '0' == str[i]) 
	kazu[j]++;
    }
  }

  for (i = 0; i < 10; i++){  
      printf("%d は %d 個含まれています.\n", i, kazu[i]);
    }

  return 0;
}
	  
