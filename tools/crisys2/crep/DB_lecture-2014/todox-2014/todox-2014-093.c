/*************************************
*
* 中間試験その２
*
* 
*
* 履歴
* 2014/12/11 09:34 作成
*************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	char content[256];
};

struct limit {
	int year;
	int month;
	int day;
};

typedef struct todo TODO;
typedef struct todo * LPTODO;

void GetString(FILE *src, char *dst,size_t size);
int ReadTodo(FILE* input, TODO * item);
void WriteTodo(FILE* output, TODO * item);
signed int CmpTodo(const void* item1, const void* item2);

int main(int nCmd, char *cCmd[])
{
	TODO items[100];/*これはメモリを食う→メモリ確保からやり直せるようにしておくべき*/
	FILE *fp=NULL;
	struct limit lim;
	int i,data_count=0;

	if(nCmd >= 3){
		fp = fopen(cCmd[2],"r");
		if(fp != NULL){
			for(i=0; !feof(fp); i++){
				ReadTodo(fp,(items+i));
				data_count++;
			}
			fclose(fp);
		}else{
			fprintf(stdout,"リストが読み込めません。\n");
			return 1;
		}
		/*ここで指定された日付をデータにしておく*/
		sscanf(cCmd[1],"%d/%d/%d",&(lim.year),&(lim.month),&(lim.day));
		/*
		ここまで来たとき、正常にデータを読み込んでいるはず
		ということでソート
		*/

		qsort(items, data_count, sizeof(TODO), CmpTodo);

		for(i=0;i<data_count;i++){
			WriteTodo(stdout,items[i]);/*全部表示されてます。*/
		}
	}

	}else{
		fprintf(stdout,"リストまたは日付が指定されていません。\n"
			"Usage: [cmd] YYYY/MM/DD [List File]\n");
		return 2;
	}
	return 0;
}

void GetString(FILE *src, char *dst,size_t size) {
	memset(dst,0,sizeof(char)*size);
	if(fgets(dst,size,src) == NULL){
		return;
	}
	if(strchr(dst,'\n') == NULL){
		while(getc(src) != '\n');
	}else{
		*( dst+(strlen(dst)-1) ) = 0;
	}
	return;
}

int ReadTodo(FILE* input, TODO *item)
{
	char buf[128];
	GetString(input,buf,128);
	sscanf(buf,"%d/%d/%d %d:%d",
			&(item->year), &(item->month), &(item->day),
			&(item->hour), &(item->minute));
	strncpy(item->content,(buf+17),(128-17));/*本当に17文字スキップでいいだろうか？*/
	return 0;
}

void WriteTodo(FILE* output, TODO *item)
{
	if(item != NULL){
		fprintf(output,
			"%4d/%2d/%2d %2d:%.2d %s\n", item->year, item->month,
			item->day, item->hour, item->minute, item->content );
	}
	return;
}

signed int CmpTodo(const void* item1, const void* item2){
	int dy,dm,dd;
	dy = ((LPTODO)(item1))->year  - ((LPTODO)(item2))->year;
	dm = ((LPTODO)(item1))->month - ((LPTODO)(item2))->month;
	dd = ((LPTODO)(item1))->day   - ((LPTODO)(item2))->day;
	if(dy>0){return 1;}
	else if(dy<0){return -1;}
	else{
		if(dm>0){return 1;}
		else if(dm<0){return -1;}
		else{
			if(dd>0){return 1;}
			else if(dd<0){return -1;}
			else{
				return 0;
			}

		}
	}
	return 0;
}

/*
void qsort(void *base, size_t nmemb, size_t size,
          int(*compar)(const void *, const void *));

qsort(items, 100, sizeof(TODO), CmpTodo);
*/

