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
} item[MAX];

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
	int i, k, year, month, day;
	
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

	return 0;
}
