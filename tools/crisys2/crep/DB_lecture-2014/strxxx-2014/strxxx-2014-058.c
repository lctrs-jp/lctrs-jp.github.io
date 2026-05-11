#include<stdio.h>

void mystrcpy(char x[],char y[]);
void mystrcat(char x[],char y[]);
int mystrlen(char y[]);
int mystrcmp(char x[],char y[]);

int main(){
  
  char str1[80],str2[80];
  int i;
  puts("第１の文字列を入力してください");
  gets(str1);
  puts("第２の文字列を入力してください");
  gets(str2);
  
  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));
  
  i = mystrcmp(str1,str2);
  if(!i){
    printf("文字列は等しい\n");
  }else if(i < 0){
    printf("%sは%sより小さい\n",str1,str2);
  }else{
    printf("%sは%sより大きい\n",str1,str2);
  }
  if((mystrlen(str1) + mystrlen(str2)) < 80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }
  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);


  return 0;
}

int mystrlen(char y[]){
   
  int i,count = 0;
  for(i = 0;y[i] != '\0';i++){
    count++;
  }
  return count;
}
void mystrcpy(char x[],char y[]){
  int len,i;
  len = mystrlen(y);
  for(i = 0; i <= len + 1;i++){
    x[i] = y[i];
  }
  return;
} 
void mystrcat(char x[],char y[]){
  int lenx,leny,i;
  lenx = mystrlen(x);
  leny = mystrlen(y);
  
  for(i = lenx;i <= lenx + leny + 1;i++){
    x[i] = y[i - lenx];
  }
  return;
}
int mystrcmp(char x[],char y[]){
  int lenx,leny,i = 0,j;
  
  while(1){ 
  if(x[i] == '\0' || y[i] == '\0') {
    j = 0;
    break;
  }
  if(x[i] != y[i]){
    if(x[i] > y[i]){
      j = 1;
      break;
    }else {
      j = -1;
      break;
    }
  }i++; 
  }
  return j;
  }
