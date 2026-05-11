#include<stdio.h>

int main(void)
{

  char str[256];
  int i, j, k, l;
  int max[256];
  int m = 0;

  printf(" Input a string:");
  scanf("%s", str);

  for( i = 0; i < 256; i++){
    if(str[i] == '\0')
      break;
  }

  /*aの数を数える
  k = 0; 
  for( j = 0; j < 256; j++){
    if((str[j] == 'a') || ( str[j] == 'A'))
      k = k +1;
    else if( str[j] == '\0')
      break;
  }
  printf("aは%d個含まれています。\n",k);
  */

  for(l = 65; l <= 90; l++){
    k = 0;
    for( j = 0; j < 256; j++){
      if((str[j] == l) || ( str[j] == l + 32))
	k = k +1;
      else if( str[j] == '\0')
	break;
    }    
    //最大のkを比較、その時のアルファベットも表示 
    //max[l] = k;
    
    if (k  > m){
      m = k;
      
      printf("%cは%d個含まれています。\n", l,k );
      //途中経過が出てしまうが最大は一応求まる。  
    }
    
  }
      
  

  return 0;
}
