#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int splite(char buf[],char *out[]);

struct event{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item[100];


int main(int argc,char *argv[])
{
  
  FILE *fp;
  int year,month,day,hour,minute;
  int date1,date2,date3,date4,date5;
  int i,j,k=0,l,m,len;
  char *out[100],buf[256];

  if(argc!=4)
    printf("Usage:プログラム名 年/月/日 時:分 ファイル名\n");
  sscanf(argv[1],"%4d/%2d/%2d",&year,&month,&day);
  sscanf(argv[2],"%2d:%2d",&hour,&minute);
  
 if((fp=fopen(argv[3],"r"))==NULL){
   printf("ファイルが開けません\n");
   exit(1);
     }
 while(fgets(buf,256,fp)!=NULL){
   len=strlen(buf);
   if(len>0&&buf[len-1]=='\n')buf[len-1]='\0';
   m=split(buf,out);
   if(m==0)continue;
   else if(m<6)fprintf(stderr,"error",argv[3],buf);
   else{
     date1=atoi(out[0]);
     item[k].year=date1;
     date2=atoi(out[1]);
     item[k].month=date2;
     date3=atoi(out[2]);
     item[k].day=date3;
     date4=atoi(out[3]);
     item[k].hour=date4;
     date5=atoi(out[4]);
     item[k].minute=date5;
     strncpy(item[k].content,out[5],256);
     k++;
   }
 }
 fclose(fp);

 for(i=0;i<k;i++){
   if((item[k].year)>year)
        printf("%4d/%2d/%2d %2d:%2d %s\n",item[k].year,item[k].month,item[k].day,item[k].hour,item[k].minute,item[k].content);
else if((item[k].year)==year){
       if((item[k].month)>month)
printf("%4d/%2d/%2d %2d:%2d %s\n",item[k].year,item[k].month,item[k].day,item[k].hour,item[k].minute,item[k].content);
       else if((item[k].day)==day){
	 if((item[k].hour)>hour)
printf("%4d/%2d/%2d %2d:%2d %s\n",item[k].year,item[k].month,item[k].day,item[k].hour,item[k].minute,item[k].content);
	 else if((item[k].hour)==hour){
	   if((item[k].minute)>minute)
printf("%4d/%2d/%2d %2d:%2d %s\n",item[k].year,item[k].month,item[k].day,item[k].hour,item[k].minute,item[k].content);
       }
     }
     }
 }
 return 0;
}

int split(char buf[], char *out[]){

  int i,j,k,m;
  i=0;
  j=strlen(buf);
  k=0;
  while(i<j){
    if(*(buf+i)!=' '||'/'||':'){
      m=i;
      while(i<j){
	if(*(buf+i)==' '||'/'||':'){
	  *(buf+i)='\0';
	  i++;
	  break;
	}
        else{
          i++;
	}
      }
      out[k]=(buf+m);
      k++;
    }
    else{
      i++;
    }
  }


  return k;
}
