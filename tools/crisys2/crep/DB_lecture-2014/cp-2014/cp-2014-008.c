#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
 { 
   FILE *from, *to; 
char ch ;

 if(argc!=3){
   printf("How to do it：<name><from><to>\n");
   exit(1);
 }

if((from = fopen(argv[1], "rb")) == NULL){ 
printf("Can’t open file\n"); 
exit(1); 
}

if((to = fopen(argv[2], "wb")) == NULL){
   printf("There has been the same name file yet\n");
   exit(1);
 }
  
 while (!feof(from)) {
   ch=fgetc(from);
   if(ferror(from)){
     printf("Error:input\n");
     exit(1);
   } 
   if(!feof(from))
     fputc(ch,to);
   if(ferror(to)){
     printf("Error:output\n");
     exit(1);
   }
 }
 
if(fclose(from) == EOF) {
  printf("Error:close (from)");
  exit(1);
}

if(fclose(to) == EOF){
  printf("Error:close(to)");
  exit(1);
 }

 return 0;

}
