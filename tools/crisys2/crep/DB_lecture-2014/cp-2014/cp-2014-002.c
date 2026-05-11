/*
コピー元のファイル名とコピー先のファイル名を引数にとり、コピーを実行する。
コピー元のファイルが存在しない・コピー先のファイルがすでに存在する場合、処理を中止
*/
#include<stdio.h>
#include<stdlib.h>

void mycopy(char* src,char* dst);   //関数copyのプロトタイプ宣言

//main関数
int main(int argc,char* argv[]){
	
	if(argc == 3){   //引数が３つのときのみコピーを実行
		mycopy(argv[1],argv[2]);
	}else{
		printf("useage:./mycopy sourcefile destfile...\n");
	}
	return 0;
}

void mycopy(char* src,char* dst){
	FILE *fp;
	FILE *ffp;
	int ch;
	
	if((fp = fopen(src, "r")) == NULL){   //読み込みのためにソースファイルを開く
		printf("sourcefile is not existed.\n");
		exit(1);
	}if((ffp = fopen(dst , "r")) != NULL){   //コピー先ファイルがすでにあればコピーをキャンセルする
			printf("copy cancel.\n");
			fclose(fp);
			exit(1);
	}
	if((ffp = fopen(dst , "w")) == NULL){   //書き込みのために新たなファイルを開く
		printf("copy cancel.\n");
		fclose(fp);
		exit(1);
	}
	
		while((ch = fgetc(fp)) != EOF){   //ファイルから１文字ずつ読み込む
				putc(ch,ffp);   //一文字ずつ書き込む
		}
	
	fclose(ffp);   //ffpファイルクローズ
	fclose(fp);   //fpファイルクローズ
	
}
