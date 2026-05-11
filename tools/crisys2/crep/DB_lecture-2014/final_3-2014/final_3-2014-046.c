#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct attendance {
  char date[9];   //日にち
  char alice;     //Aliceの都合
  char bob;       //Bobの都合
  char carol;     //Carolの都合
  int ok;         //参加可能な人数
  int unfixed;    //参加未定(?)の人数
} det[30],*p;

int main (int argc, char *argv[])
{
  FILE *fp;
  char str[100], name[3][10],exname[10],date[9],tugou;
  int i, t, count = 0,day,month,year,n;

  if (argc != 4){
    printf("3つのファイル名を指定して実行してください（例） alice.txt bob.txt carol.txt\n\n");
    exit(1);
  }
  
  for (i = 0;i < argc-1; i++){
    
    if ((fp = fopen(argv[i+1], "rb")) == NULL){
      printf("ファイル(%s)がディスク上に存在しません。\n",argv[i+1]);
      exit(1);
    }
    
    //最初に名前があるので読み込む
    fgets(str,100,fp);
    sscanf(str,"#%s",exname);

    //入力された順番に都合を表示するために、一行目を調べる

    if (strcmp(exname, "Alice") == 0){
      strcpy(name[i], exname);
      while (fgets(str,100,fp) != NULL){	
	sscanf(str,"%s %c",date,&(tugou));
	for (t = 0, p = det; t < count && strcmp(p->date,date) != 0; t++, p++);
	//一個目に読み込むものか新しいものなら新規追加の処理
	if (count == 0 || t == count){
	  strcpy(p->date,date);
	  p->alice = tugou;
	  count++;
	  //すでに同じ日付がある場合、データを増やすだけの処理
	}else
	  p->alice = tugou;
	if (tugou == 'o'){
	  if (i == 0)
	    p->ok = 0;	  
	  p->ok++;
	}else if (tugou == '?'){
	  if (i == 0)
	    p->unfixed = 0;
	  p->unfixed++;
	}
      }
      
    }else if (strcmp(exname, "Bob") == 0){
      strcpy(name[i], exname);
      p = det;
      while (fgets(str,100,fp) != NULL){	
	sscanf(str,"%s %c",date,&(tugou));
	for (t = 0, p = det; t < count && strcmp(p->date,date) != 0; t++, p++);
	//一個目に読み込むものか新しいものなら新規追加の処理
	if (count == 0 || t == count){
	  strcpy(p->date,date);
	  p->bob = tugou;
	  count++;
	  //すでに同じ日付がある場合、データを増やすだけの処理
	}else
	  p->bob = tugou;
	if (tugou == 'o'){
	  if (i == 0)
	    p->ok = 0;	  
	  p->ok++;
	}else if (tugou == '?'){
	  if (i == 0)
	    p->unfixed = 0;
	  p->unfixed++;
	}
      }
      
    }else if (strcmp(exname, "Carol") == 0){
      strcpy(name[i], exname);
      p = det;
      while (fgets(str,100,fp) != NULL){	
	sscanf(str,"%s %c",date,&(tugou));
	for (t = 0, p = det; t < count && strcmp(p->date,date) != 0; t++, p++);
	//一個目に読み込むものか新しいものなら新規追加の処理
	if (count == 0 || t == count){
	  strcpy(p->date,date);
	  p->carol = tugou;
	  count++;
	  //すでに同じ日付がある場合、データを増やすだけの処理
	}else
	  p->carol = tugou;
	if (tugou == 'o'){
	  if (i == 0)
	    p->ok = 0;	  
	  p->ok++;
	}else if (tugou == '?'){
	  if (i == 0)
	    p->unfixed = 0;
	  p->unfixed++;
	}
      }
      
    }else {
      printf("読み込みエラー\n");
      exit(1);
    }
    fclose(fp);
    
  }
  
  //データの表示
  printf("date\t\t%s\t%s\t%s\n",name[0],name[1],name[2]);
  printf("-----------------------------------------------------\n");
 
  for (i = 0, p = det; i < count; i++,p++) {
    sscanf(p->date,"%d",&n);
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",year,month,day,p->alice,p->bob,p->carol);

  }


  printf("-----------------------------------------------------\n");
  for (i = 0, p = det; i < count; i++,p++) {
    sscanf(p->date,"%d",&n);
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
    printf("%4d/%2d/%2d [ok:%d, ?:%d]\n",year,month,day,p->ok,p->unfixed);

  }





  return 0;

}
