#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split(char buf[], char *out[]); 
void str(char str[]);
//元のソースプログラムではうまく動かなかったので、main関数を変更
int main(void)
{
  int i,j;
  char *out[80],buf[80];
  printf("文字を入力してください:");
  fgets(buf,80,stdin);
  str(buf);
  j=split(buf,out);
  for(i=0;i<j;i++){
    printf(*(out+i));
    if(i==j)
      break;
        printf("\n");
  }
  printf("文字数は%dです。",j);
   return 0;
}


int split(char buf[], char *out[]){
  int i,k,j,p,q,r,s,t;
  char *poi;
  //一番初めのスペースを抜く
 p=strlen(buf);
  while(buf[0]==' '&&p!=0){
    for(i=0;buf[i];i++)
      buf[i]=buf[i+1];  
    p--;  
  }

  //連続するスペースを抜く 
  k=0;
  p=strlen(buf);
    while(k<=p){
    if(buf[k]==' '&&buf[k+1]==' '){
      for(j=0;buf[j+k+1];j++){
	buf[k+j+1]=buf[k+j+2];
      }
      k=0;
    }
    k++;
    }
    //最後のスペースを抜く
  p=strlen(buf);
  while(buf[p-1]==' '){
    buf[p-1]='\0';
    p--;
  }

  //空白の数を数えていく。
  s=0;
  p=strlen(buf);
  poi=buf;
  if(p!=0){
    for(q=0;q<p;q++){
      if(*poi==' ')
	s=s+1;
      poi++;
}
    s=s+1;   
  }


  //スペースの後ろからヌル文字を挿入(ソースプログラムでのエラーの原因？) 
  r=s;
  while(r>0){
    t=0;
    poi=buf;
    while(t>=0){
      if(*poi==' ')
        t=t+1;
      if(t==r)
        break;
      
      poi++;
    }
    *(out+r)=poi+1;
    *poi='\0';
    r--;
  }
  *out=buf;
   return s;
}


//改行文字をなくす関数
void str(char str[])
{
  int i;
  i=strlen(str);
  if(str[i-1]==10&&str[i-2]==10)
    str[i-1]='\0';
  else if(str[i-1]==10&&str[i-2]!=10)
    str[i-1]='\0';

  return;
}
