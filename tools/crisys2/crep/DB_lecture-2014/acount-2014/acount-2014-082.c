#include<stdio.h>

void downcase(char str[]);
int main(void){

  
  char str[101],maxstr[27] ;
  int max = 0,count,i,j,k,l;

  printf("文字列を入力してください(長さ100以下):");
  fgets(str,100,stdin);

  downcase(str);

  for(i = 0;str[i];i++){
    count = 0;
    for(j = 0;str[j];j++){
      if(str[j] == str[i])
	count++;
    }
    if(count > max){
      k = 0;
      max = count;
      maxstr[k] = str[i];
      maxstr[k + 1] = '\0';
    
    }
  }
  printf("最頻出文字は%s\n",maxstr);
  printf("出現回数は%d回\n",max);
    
  return 0;

}

void downcase(char  str[]){
  int i;
  for(i = 0;str[i];i++)
    if(str[i] >= 'A' && str[i] <='Z')
      str[i] -= 'A' -'a';
  return;
}
