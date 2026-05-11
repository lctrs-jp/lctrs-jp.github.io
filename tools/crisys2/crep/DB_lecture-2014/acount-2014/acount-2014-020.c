#include<stdio.h>
int main()
{char s[81],a,c;
  int b,d,e,f;
  printf("80字以内で文を入力してください");
  fgets(s,81,stdin);
  e=0;
  for(a=65,f=97;a<91,f<123;a++,f++){
    d=0;
    for(b=0;s[b]!='\0';b++){	
      if(s[b]=a){
	d=d+1;
      }
      if(s[b]=f){
	d=d+1;
      }
    }
    if(e<d)
      {
	e=d;
	c=a;
      }        
  }
  printf("一番多い文字は%cです",c);
  return 0;
}
