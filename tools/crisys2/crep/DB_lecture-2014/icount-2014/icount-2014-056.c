#include <stdio.h>

int main(void)
{
  int i, j[10], k;
  char str[101];

  printf("文字列を入力してください(100文字以内)\n");
  scanf("%s", str);
  

  for(k = 0; k < 10; k++)
    j[k] = 0;
  

  for(i = 0; str[i] != '\0'; i++){
    if(str[i] == '0')
      j[0] = j[0] + 1;
    if(str[i] == '1')
      j[1] = j[1] + 1;
    if(str[i] == '2')
      j[2] = j[2] + 1;
    if(str[i] == '3')
      j[3] = j[3] + 1;
    if(str[i] == '4')
      j[4] = j[4] + 1;
    if(str[i] == '5')
      j[5] = j[5] + 1;
    if(str[i] == '6')
      j[6] = j[6] + 1;
    if(str[i] == '7')
      j[7] = j[7] + 1;
    if(str[i] == '8')
      j[8] = j[8] + 1;
    if(str[i] == '9')
      j[9] = j[9] + 1;

  }
      printf("0 は%d個含まれています\n", j[0] ); 
      printf("1 は%d個含まれています\n", j[1] ); 
      printf("2 は%d個含まれています\n", j[2] ); 
      printf("3 は%d個含まれています\n", j[3] ); 
      printf("4 は%d個含まれています\n", j[4] ); 
      printf("5 は%d個含まれています\n", j[5] ); 
      printf("6 は%d個含まれています\n", j[6] ); 
      printf("7 は%d個含まれています\n", j[7] ); 
      printf("8 は%d個含まれています\n", j[8] ); 
      printf("9 は%d個含まれています\n", j[9] ); 

     
    


  return ;
}
  
