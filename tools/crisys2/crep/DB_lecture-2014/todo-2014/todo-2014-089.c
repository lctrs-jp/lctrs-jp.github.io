#include <stdio.h>
#include <stdlib.h>
struct todo{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	char content[256];
}td[100];


int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[100];
	int yr, mh, dy, ,hr, me, id, j, sum[100], a, b, spsum,t;
	id=0;

	if (argc != 3) {
    printf("プログラム名　年/月/日 ファイル名\n");
    exit(1);
	}
	  //open file
	if ((fp = fopen(argv[1], "r")) == NULL) {
    	printf("ファイルを開けません\n");
    	exit(1);
	}
	//coppy date
	while( fgets(buf,200,fp) != NULL ){
		sscanf(buf,"%d/%d/%d %d:%d",&yr, &mh, &dy, &hr, &me);
		td[id].year = yr;
		td[id].month = mh;
		td[id].day = dy;
		td[id].hour = hr;
		td[id].minute = me;
		strcpy(td[id].content,&buf[17]);
		sum[id] = yr*100000000 + mh*1000000 + dy*10000 + hr*100 + me;
		id++;
	}
	j=id;
	 for (a = 1; a < id; a++)
		for (b = id-1; b >= a; b--){
			if (sum[b-1] > sum[b]){
				t = sum[b-1];
				sum[b-1] = sum[b];
				sum[b] = t;
			}
		}
	sscanf(argv[2],"%d/%d/%d", &yr, &mh, &dy );
	spsum = yr*100000000 + mh*1000000 + dy*10000;

	for (id = 0; id < j; id++)
	if (sum[id] >= spsum){
		printf("%d/%d/%d %d:%d %s",td[id].year, td[id].month, td[id].day,
			td[id].hour, td[id].minute, td[id].content);
	};
  return 0;
}
