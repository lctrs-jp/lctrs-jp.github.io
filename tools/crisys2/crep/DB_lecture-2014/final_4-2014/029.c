#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct attendance {
	char date[9]; // 日にち
	char alice;   // Aliceの都合
	char bob;     // Bobの都合
	char carol;   // Carolの都合
	int ok;       // 参加可能な人数
	int unfixed;  // 参加未定（?）の人数
};

void rement(char* buf){
	int len=strlen(buf);
	if(len==0&&buf[len-1]=='\n')
		buf[len-1]='\0';
	return;
}

void ini(struct attendance item[30]){
	int i;
	for(i=0;i<30;i++){
		item[i].date[0]=0; 
		item[i].alice=0;
		item[i].bob=0;     
		item[i].carol=0;   
		item[i].ok=0;       
		item[i].unfixed=0;
	}
	return;
}
		

int load(struct attendance item[30],char *fname[]){
	FILE *fp;
	int size=0,n=1,j;
	char buf[11],ans;
	
	
	
	while(n<4){
		if((fp=fopen(fname[n],"r"))==NULL)
    	{
			printf("ファイル%sを開けませんでした\n",fname[n]);
			exit(1);
    	}
		if(fgets(buf,11,fp)!=NULL){
			rement(buf);
			if(strcmp("#Alice",buf)!=0){
			}else if(strcmp("#Bob",buf)!=0){
			}else if(strcmp("#Carol",buf)!=0){
			}else{
				printf("ファイルの形式が間違っています\n");
				return 0;
			}
			
		}else{
			printf("ファイルの形式が間違っています\n");
			fclose(fp);
			return 0;
		}
		while(fgets(buf,11,fp)!=NULL){
			rement(buf);
			for(j=0;j<size;j++){
				if(strncmp(buf,item[j].date,8)==0)
					break;
			}
			if(j==size)
				size++;
    		sscanf(buf, "%s %c", item[j].date,&ans);
			if(n==1)
				item[j].alice=ans;
			if(n==2)
				item[j].bob=ans;
			if(n==3)
				item[j].carol=ans;
			if(ans=='o')
				item[j].ok++;
			if(ans=='?')
				item[j].unfixed++;
    	}
		fclose(fp);
		n++;
		
	}
	return size;
}

void display(int size,struct attendance item[30]){
	int i,year,month,day,n;
	
	printf("date\t\tAlice\tBob\tCarol\n");
	printf("-------------------------------------\n");
	for(i=0;i<size;i++){
		sscanf(item[i].date,"%d",&n);
		day = n % 100;
		month = (n / 100) % 100;
		year = n / 10000;
		printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",year,month,day,item[i].alice,item[i].bob,item[i].carol,
			item[i].ok,item[i].unfixed );
	}
	printf("-------------------------------------\n");
	return;
}

int comp(const void *a,const void *b){
	struct attendance x=*(struct attendance *)a;
	struct attendance y=*(struct attendance *)b;
	if(y.ok-x.ok!=0)
		return y.ok-x.ok;
	return y.unfixed-x.unfixed;
}

void display2(int size,struct attendance item[30]){
	int i,year,month,day,n,j=0,t1=0,t2=0;
	
	qsort(item,30,sizeof(struct attendance),comp);
	

	for(i=0;i<size;i++){
		sscanf(item[i].date,"%d",&n);
		day = n % 100;
		month = (n / 100) % 100;
		year = n / 10000;
		if(t1-item[i].ok==0&&t2-item[i].unfixed==0){
		}else{
			j=i+1;
		}
		t1=item[i].ok;
		t2=item[i].unfixed;
		
		printf("%2d: %4d/%2d/%2d\t[o:%d, ?:%d]\n",j,year,month,day,item[i].ok,item[i].unfixed );
	}
	return;
}
	


int main(int args,char *argv[]){
	struct attendance item[30];
	int size;

	ini(item);
	if(args<4){
		printf("ファイル名を３つ起動時引数に入力してください\n");
		exit(1);
	}
	size=load(item,argv);
	fprintf(stdout,"%d",size);
	display(size,item);
	display2(size,item);

	return 0;
}
