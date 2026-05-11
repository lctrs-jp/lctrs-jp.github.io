#include<stdio.h>
int main(){
  int s[255];
  int a,b,c,d,e;
  printf("数をいくつ入力するの？");
  scanf("%d",&a);
  if(a>254)
    while(a>254){
      printf("ちょっと多すぎよ…考え直して");
      scanf("%d",&a);}
    printf("じゃあ、打ち込んでみて\n");
    for(b=0;b<a;b++){
      scanf("%d",&s[b]);}
    printf("了解！\n");
    for(b=1;b<a;++b)
    for(c=a-1;c>=b;--c){
      if(s[c-1]>s[c]){
	d=s[c-1];
	s[c-1]=s[c];
	s[c]=d;
	for(e=0;e<a;e++){
	  printf("%d",s[e]);}
	printf("\n");
      }
    }
      for(e=0;e<a;e++){
	printf("%d",s[e]);}
	  return 0;
}
