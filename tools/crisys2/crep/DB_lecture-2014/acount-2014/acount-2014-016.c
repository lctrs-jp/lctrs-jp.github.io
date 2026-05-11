#include<stdio.h>
#include<string.h>

int main(void)
{
  char s[100];
  char m;
  int h,i,j,k,l,max;
  int a[26];
  for(i=0;i<26;i++)
	a[i]=0;
  max=0;
  printf("文字を入力してください\n");
    fgets(s,100,stdin);
    j=strlen(s);
    for(i=0;i<j;i++)
      if('a'<=s[i]&&s[i]<='a')
        s[i]=s[i]-'a'+'A';
    for(i=0;i<j;i++){
      for(k=65;k<90;k++){
	if(s[i]==k)
          a[k-65]++;
      }
    }
    for(l=0;l<26;l++){
      if(a[l]>max)
	max=a[l]; 
    }
    printf("最頻出文字\n");
    for(i=0;i<26;i++){
      if(a[i]==max){
	  h=i+65;
          m=h;
	  printf("%c:%d個\n",m,max);
      }
    }
    return 0;
}    
