#include<stdio.h>

int mystrlen(char x[]);
int mystrcmp(char x[],char y[]);
void mystrcat(char x[],char y[]);
void mystrcpy(char x[],char y[]);

int main(){
  char str1[80],str2[80];
  int i;

  printf("第一の文字列を入力してください。：");
  gets(str1);
  printf("第二の文字列を入力してください。：");
  gets(str2);

  printf("%sは%d文字の長さです。\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです。\n",str2,mystrlen(str2));

  i=mystrcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);


  if((mystrlen(str1)+mystrlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);
  return 0;
}

int mystrlen(char x[]){
  int k,count=0;
  for(k=0;x[k];k++){
    count=count+1;
  }
  return count;
}

int mystrcmp(char x[],char y[]){
  int n=0,k;
  for(k=0;n==0&&x[k]&&y[k];k++){
    if(x[k]<y[k]){
      n=-1;
    }
    else if(x[k]>y[k]){
      n=1;
    }
    else if(x[k]&& !y[k]){
      n=1;
    }
    else if(y[k]&& !x[k]){
      n=-1;
    }
  }
  return n;
}

void mystrcat(char x[],char y[]){
  int k,last=0,length=0;

  for(k=0;x[k];k++){
    last=last+1;
  }
  for(k=0;y[k];k++){
    length=length+1;
  }
  for(k=0;k<=length;k++){
    x[last]=y[k];
    last++;
  }
}

void mystrcpy(char x[],char y[]){
  int i;
  for(i=0;y[i];i++){
    x[i]=y[i];
    if(!(y[i+1])){
      x[i+1]='\0';
    }
  }
}
