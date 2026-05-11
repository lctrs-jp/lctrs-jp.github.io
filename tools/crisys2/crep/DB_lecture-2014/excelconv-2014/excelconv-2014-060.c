#include<stdio.h>
#include<string.h>

int conv(char *str);
int main(int argc,char *argv[]){

  int i = 0;

  printf("%d\n",conv(argv[1]));
  return 0;
}
int conv(char *str){
  int i,k,j = 0,l,max = 0;

  for(i = 0;str[i];i++){
    str[i] -= 64;
  }
  for(;i > 0;i--){
    k = (int)str[j++];
    for(l = 0;l != (i - 1);l++)
      k *= 26;

  max += k;

  }
  return max;
}
