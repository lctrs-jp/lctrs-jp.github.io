#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  
  
  int y[5]={0,0,0,0,0};
  int i, j;
  j=1;
   
      
  for(i=strlen(argv[1])-1 ; i>=0; i--){
    y[i]=(argv[1][i]-64)*j;
    j=j*26;    
  }
printf("%d\n",y[1]+y[2]+y[3]+y[4]+y[0]);
    return 0;
}










