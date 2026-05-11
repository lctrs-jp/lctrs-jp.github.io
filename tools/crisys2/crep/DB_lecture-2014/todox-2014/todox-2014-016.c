#include<stdio.h>

int main(int argc, char *argv[])
{
  
  struct todo {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    char content[99];
  };

  FILE *mytodo;
  int i,j,x,y,z;
  char argv[2];
  
  if(argc!=3)
    {fprintf(stderr,"ファイルを開くことができません\n",argv[0]);
      exit(1);}
   

  sscanf(argc[1],"%d/%d/%d",&a,&b,&c);

  FILE *fopen(argv[2], char *r+);

  *fgets(*content,99,FILE*argv[2]);  

  j=strlen(content);

  for(i=0;content[i]!='\0';i++);
  if(content[i]==' ')
      content[i]='\0';
  
  for(i=0;i=j;i++);
  {if(content[i+4]=='/'&&content[i+4+2]=='/'&&content[i+4+2+2]=='/')
      sscanf(content,"%d/%d%d/"



}
