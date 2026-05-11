#include<stdio.h>

int main(void)
{char w[10],c[1];
  int count[26],k,i;
  for(k=0;k!=26;k++)
    count[k]=0;
  printf("文字を入力してください（10文字以内で)");
  fgets(w,10,stdin);
  for(i=0;w[i]!='\0';i++)
{
    /*大文字と小文字を同じに*/
	if('A'<=w[i]&&w[i]<='Z')
	  w[i]=w[i]+('a'-'A');
	if('a'<=w[i]&&w[i]<='z')
	  count[w[i]-'a']++;
	for(i=0;i<26;i++)
	  printf("%d %d\n",i,count[i]);}
    return;      }
