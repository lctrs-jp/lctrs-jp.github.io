//期末試験課題２
//********* ****

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 100

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
}item;

int load(char *filename);

int okq(char *okx[]);

int main(int argc,char *argv[])
{
 
  int n, year, month, day;
  int i,size;

  if(argc<4){
		printf("Usage: %s filename1 ... filename3\n",argv[0] );
        exit(1);
  }

 
  for (i = 1;i < argc;i++){
    load(argv[i]);
  }

  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol,
	 item.ok, item.unfixed );


  return 0;
}

int load(char *filename)//ファイルの読み込み
{

 FILE *fp;
  char buf[LEN],name[LEN],okx[LEN];
  int len,date,size;
  int year,month,day,n;

  if ((fp = fopen (filename, "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました", filename); exit (1);
  }

   fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(name,&buf[1]);
  size = 0;

  if(filename == "alice.txt"){
	 while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n') buf[len-1] = '\0'; 

	sscanf(buf,"%d %c", &date, &okx[0]);
	size++;
	okq(okx[0]);
  }
	
  }
  if(filename == "bob.txt"){
	 while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    
    if( len >0 && buf[len-1]=='\n') buf[len-1] = '\0';
    
   	sscanf(buf,"%d %c", &date, &okx[1]);
	size++;
	okq(okx[1]);
  }  
  }

  if(filename == "Carol.txt"){
   while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    
    if( len >0 && buf[len-1]=='\n') buf[len-1] = '\0';
  	sscanf(buf,"%d %c", &date, &okx[0]);
	size++;
	okq(okx[2]);
  }
  }
  
  n = date;

  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("%4d/%2d/%2d",year, month, day);

   printf("\t\t%c\%c\t%c\t\n",date,okx[0],okx[1],okx[2]);


}


int okq(char *ok[]){
	int i;
	for(i=0;i<3;i++){
		if(ok[i] == 'o') item.ok++;
		if(ok[i] == '?') item.unfixed++;
	}

}
