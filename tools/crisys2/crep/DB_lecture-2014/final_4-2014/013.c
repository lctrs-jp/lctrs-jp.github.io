#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct attendance {
	char date[9]; 	/* 日にち*/
	char alice;	 	/* Aliceの都合*/
	char bob;		/* Bobの都合*/
	char carol;		/* Carolの都合*/
	int ok;			/* 参加可能な人数*/
	int unfixed;	/* 参加未定（?）の人数*/
};

typedef struct attendance    ATTENDANCE;
typedef struct attendance* LPATTENDANCE;

int readfile(FILE* fp, LPATTENDANCE list, int dcount){
	char buf[64];
	char day[32], name[32], ans;
	int  tmp,i,length;
	
	memset(buf,0,sizeof(buf));
	memset(day,0,sizeof(day));

	fgets(buf,sizeof(buf),fp);
	sscanf(buf,"#%s",name);

	while( fgets(buf,sizeof(buf),fp)!=NULL){
		length = strlen(buf);
		if(length>0 && buf[length-1]=='\n'){
			buf[length-1] = '\0';
		}			
		sscanf(buf,"%s %c",day,&ans);
		/*予定リストを読んで、その日のレコードが存在するか確認*/
		for(i=0;i<dcount;i++){
			if( strncmp(day, list[i].date, 8)==0 ){
				tmp=i;
				break;
			}
		}
		if(i == dcount){
			/*初出なら一番後ろに追加*/
			strncpy(list[dcount].date, day, 8);
			tmp=dcount;
			dcount++;
		}
		/*データセット*/
		if(strcmp(name,"Alice")==0){
			list[tmp].alice = ans;
		}else if(strcmp(name,"Bob")==0){
			list[tmp].bob = ans;
		}else if(strcmp(name,"Carol")==0){
			list[tmp].carol = ans;
		}else{
			perror("cannot handle this file:Data input");
			return -1;
		}
	}
	return dcount;
}

void adjust(LPATTENDANCE list){
	int data;
	for(data=0; data<MAX; data++){
		/*oの集計*/
		if(list[data].alice=='o'){
			list[data].ok+=1;
		}
		if(list[data].bob=='o'){
			list[data].ok+=1;
		}
		if(list[data].carol=='o'){
			list[data].ok+=1;
		}
		/*?の集計*/
		if(list[data].alice=='?'){
			list[data].unfixed+=1;
		}
		if(list[data].bob=='?'){
			list[data].unfixed+=1;
		}
		if(list[data].carol=='?'){
			list[data].unfixed+=1;
		}
	}
}

int echodata(LPATTENDANCE list, int count){
	int day, month, year, tmp, line;

	printf("date\t\tAlice\tBob\tCarol\n");
	printf("-------------------------------------\n");
	for(line = 0; line<count; line++){
		sscanf( list[line].date, "%d", &tmp);
		day = tmp % 100;
		month = (tmp / 100) % 100;
		year = tmp / 10000;
		printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
				year, month, day,
				list[line].alice, list[line].bob, list[line].carol);
	}
	printf("-------------------------------------\n");
	return line;
}

int echoadjust(LPATTENDANCE list, int count){
	int day, month, year, tmp, line;

	for(line = 0; line<count; line++){
		sscanf( list[line].date, "%d", &tmp);
		day = tmp % 100;
		month = (tmp / 100) % 100;
		year = tmp / 10000;
		printf("%2d: %4d/%2d/%2d\t[ok:%d, ?:%d]\n",
				(line+1), year, month, day,
				list[line].ok, list[line].unfixed);
	}
	return line;
}

int cmpDataByDate(const void *o1, const void *o2){
	return strncmp( ((LPATTENDANCE)o1)->date, ((LPATTENDANCE)o2)->date, 8);
}

int cmpDataByFreer(const void *o1, const void *o2){
	int tmp=0;
	tmp = (((LPATTENDANCE)o2)->ok) - (((LPATTENDANCE)o1)->ok);
	if(tmp==0){
		tmp = (((LPATTENDANCE)o2)->unfixed) - (((LPATTENDANCE)o1)->unfixed);
	}
	return tmp;
}

int main(int nCmd, char *cCmd[]){
	struct attendance list[MAX];
	int count=0, i;
	FILE *fp[MAX];
	
	/*配列初期化
	不定データへのアクセスを防ぐため。*/
	for(count=0; count<MAX; count++){
		memset(list[count].date,0,sizeof(list[count].date));
		list[count].alice=0;
		list[count].bob  =0;
		list[count].carol=0;
		list[count].ok   =0;
		list[count].unfixed=0;
	}
	count=0;

	/*コマンドライン引数の数確認*/
	if(nCmd<4){
		perror("At least 3 files are required.");
		exit(1);
	}

	/*データファイルオープン*/
	fp[0] = fopen(cCmd[1],"r");
	fp[1] = fopen(cCmd[2],"r");
	fp[2] = fopen(cCmd[3],"r");
	if( (fp[0]==NULL) || (fp[1]==NULL) || (fp[2]==NULL) ){
		perror("cannot open files");
		exit(2);
	}

	/*予定を読み込む*/
	for(i=0; i<3; i++){
		count = readfile(fp[i],list,count);
		if( count==(-1)){
			perror("cannot handle this file");
			exit(4);
		}
	}

	qsort(list, count, sizeof(ATTENDANCE), cmpDataByDate);
	echodata(list,count);
	
	adjust(list);
	qsort(list, count, sizeof(ATTENDANCE), cmpDataByFreer);
	echoadjust(list,count);
	
	fclose(fp[2]);
	fclose(fp[1]);
	fclose(fp[0]);

	return 0;
}
