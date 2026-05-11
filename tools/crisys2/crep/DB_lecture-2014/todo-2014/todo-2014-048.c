#include <stdio.h>
#include <string.h>

struct todo {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	char content[256];
} item[100];

int n = 0;

void load(char *fname){
	FILE *fp;
	char buf[256];
	int len;
	if((fp = fopen(fname,"r")) != NULL){
		while((fgets(buf,256,fp)) != NULL){
			if((len=strlen(buf)) >0 && buf[len-1]=='\n')
				buf[len-1]='\0';
			sscanf(buf, "%4d/%2d/%2d %2d:%.2d", &item[n].year, &item[n].month, &item[n].day, &item[n].hour, &item[n].minute);
			strcpy(item[n].content,buf+18);
			n++;
		}
	}
}

int main(int argc, char *argv[])
{
	load(argv[2]);
	
	int i, x, y, z;
	
	sscanf(argv[1], "%4d/%2d/%2d", &x, &y, &z);
	
	for(i = 0;i < n;i++){
		if(x==item[i].year && y==item[i].month && z==item[i].day){
			break;
		}
	}
	for(;i < n;i++){
		printf("%4d/%2d/%2d %2d:%.2d %s\n", item[n].year, item[n].month, item[n].day, item[n].hour, item[n].minute, item[n].content);
	}
	
	
  return 0;
}
