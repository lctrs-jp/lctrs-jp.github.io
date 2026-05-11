#include <stdio.h> 
#include <stdlib.h> 

int main(int argc,char*argv[])
{
  FILE* fp;
  char* buf;
  int reteral=0;
  size_t i,len; 

  if (argc>1&&(fp=fopen(argv[1],"r"))){
    fseek(fp,0,SEEK_END);
    len=ftell(fp);
    buf=(char*)malloc(len);rewind(fp);
    fread(buf,len,1,fp);
    fclose(fp); 

    for(i=0;i<len;i++) {
      if(!reteral&&buf[i]=='/'&&(i+1)<len&&buf[i+1]=='/') {
	i+=2; 
	while(i<len&&buf[i]!='\n')i++;
      } else if(!reteral&&buf[i]=='/'&&(i+1)<len&&buf[i+1]=='*') {
	i+=2; 
	while(i<len&&!(buf[i]=='*'&&(i+1)<len&&buf[i+1]=='/'))i++;
	i+=2;
      } else if((buf[i]=='\"'||buf[i]=='\'')&&(buf[i-1]!='\\')) {
	reteral=!reteral;
      }
      putchar(buf[i]);
    }
  }
  return 0;
} 
