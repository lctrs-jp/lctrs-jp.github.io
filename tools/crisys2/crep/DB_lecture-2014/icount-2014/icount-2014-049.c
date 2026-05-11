#include <stdio.h>
#include <string.h>
int main(){

char a[60];
 int i,t,b[9];
 for(i=0;i<9;i++)
   b[i]=0;
 printf("数字を入力してください");
   fgets(a,60,stdin);
 if(a[strlen(a)]=='\n')
   a[strlen(a)]='\0';

 for(t=0;t<strlen(a);t++){
   for(i=0;i<10;i++){
     if(a[t]<58&&a[t]>47){
     if(a[t]==i+48){
       b[i]=b[i]+1;}
}
     else
       break;
 }
 }
   for(i=0;i<10;i++)
     printf("%d は %d 個含まれています\n",i,b[i]);

   return 0;
 }
       
   
