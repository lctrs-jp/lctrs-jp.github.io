#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

struct attendance {
	char date[9]; // 日にち
	char alice[5];   // Aliceの都合
	char bob[5];     // Bobの都合
	char carol[5];   // Carolの都合
	int ok;       // 参加可能な人数
	int unfixed;  // 参加未定（?）の人数
	int year;
	int month;
	int day;
} item[MAX], temp;


int n = 0;

void load(char *fname)
{
	int i, j;
	FILE *fp;
	char name[30], buf[256], temp_date[9], temp_com[5];
	if((fp = fopen(fname,"r")) != NULL){
		fgets(buf,256,fp);
		sscanf(buf, "#%s", name);
		while((fgets(buf,256,fp)) != NULL){
			sscanf(buf, "%s %s", temp_date, temp_com);
			for(i = 0; i < n; i++){
				if(strncmp(item[i].date, temp_date, 30) == 0){
					j = i;
					break;
				}
			}
			if( i == n){
				strcpy(item[i].date, temp_date);
				j = n;
				n++;
			}
			
			if(strncmp(name, "Alice", 50) == 0)
				strcpy(item[j].alice, temp_com);
			else if(strncmp(name, "Bob", 50) == 0)
				strcpy(item[j].bob, temp_com);
			else if(strncmp(name, "Carol", 50) == 0)
				strcpy(item[j].carol, temp_com);
		}
	}
	fclose(fp);
}


int main(int argc, char *argv[])
{
	int a, b, i, k, year, month, day;
	
	load(argv[1]);
	load(argv[2]);
	load(argv[3]);
	
	printf("date\t\tAlice\tBob\tCarol\n");
	for(i = 0; i < n; i++){
		sscanf( item[i].date, "%d", &k );
		day = k % 100;
		month = (k / 100) % 100;
		year = k / 10000;
	printf("%4d/%2d/%2d\t%s\t%s\t%s\t\n",
	year, month, day,
	item[i].alice, item[i].bob, item[i].carol );
	}
	
	printf("-----------------------------------------------\n");
	for(i = 0; i < n; i++){
		sscanf( item[i].date, "%d", &k );
		item[i].day = k % 100;
		item[i].month = (k / 100) % 100;
		item[i].year = k / 10000;
		
		item[i].ok = 0;
		item[i].unfixed = 0;
		
		if(strncmp(item[i].alice, "o", 5) == 0)
		item[i].ok++;
		if(strncmp(item[i].alice, "?", 5) == 0)
		item[i].unfixed++;
		if(strncmp(item[i].bob, "o", 5) == 0)
		item[i].ok++;
		if(strncmp(item[i].bob, "?", 5) == 0)
		item[i].unfixed++;
		if(strncmp(item[i].carol, "o", 5) == 0)
		item[i].ok++;
		if(strncmp(item[i].carol, "?", 5) == 0)
		item[i].unfixed++;
	}
	
	for(a=1; a<n; a++){
		for(b=n-1;b>=a;b--){
			if((item[b-1].ok < item[b].ok) || (item[b-1].ok == item[b].ok && item[b-1].unfixed < item[b].unfixed)){
				temp = item[b-1];
				item[b-1] = item[b];
				item[b] = temp;
			}
		}
	}
	
	for(i = 0; i < n; i++){
		printf("%4d/%2d/%2d\t[ok:%d, ?:%d]\n", item[i].year, item[i].month, item[i].day, item[i].ok, item[i].unfixed);
	}
	
	
	return 0;
}
