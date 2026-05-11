/*****************************
* bmi.c
* *********
* ******** *********
* -----更新履歴-----
* 2014/10/09 21:32 初版
* 2014/10/16 09:04 体重の単位をkgに修正
*                  BMIの表示形式を変更
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*入力を求めるかどうかのフラグ*/
#define FLAG_T 1
#define FLAG_W 2

/*入力バッファサイズ*/
#define BUF_SIZE 32

int main(int nCmd,char* cCmd[])
{
	double height=-1.0, weight=-1.0,bmi=-1.0;
	char flag = (FLAG_T | FLAG_W);
	char *buf;

	/*コマンドライン引数があれば数値として対応*/
	if(nCmd >= 3)
	{
		fprintf(stdout,"Using Params...\n");
		{
		/*	errno = 0;*/
			errno^=errno;
			height=strtod(cCmd[1],(char **)NULL);
			if(errno==0)
			{
				flag^=FLAG_T;
			}
		}
		{
			errno^=errno;
			weight=strtod(cCmd[2],(char **)NULL);
			if(errno==0){flag^=FLAG_W;}
		}
	}

	/*身長を聞くフラグが立っていたら入力を求める*/
	if(flag&FLAG_T)
	{
		/*scanf()だとバッファオーバーフローを起こさない自信がない。
		そのうえcharが1バイトだという保証もない。*/
		buf = (char *)malloc(sizeof(char)*BUF_SIZE);
		if(buf==NULL)
		{
			/*メモリ不足はどうしようもないのでAbortします*/
			fprintf(stderr,"Memory allocation failed! [[Abort]]\n");
			/*メモリ確保前なので解放はできない*/
			return -1;
		}
		memset(buf,0,sizeof(char)*BUF_SIZE);
		fprintf(stdout,"Hight[m]:");
		if(fgets(buf,BUF_SIZE,stdin) == NULL)
		{
			fprintf(stderr,"Reading input failed! [[Abort]]\n");
			/*メモリ確保後なのでメモリを解放する*/
			free(buf);
			return -1;
		}
		if(strchr(buf,'\n') == NULL)
		{
			/*バッファクリア中のエラーは対応がわからないので無視します。*/
			while(getc(stdin) != '\n');
		}else{
			*( buf+(strlen(buf)-1) ) = 0;
		}
		errno^=errno;
		height=strtod(buf,(char **)NULL);
		if(errno!=0)
		{
			/*数値変換できない文字列が与えられた場合，ループせずにAbortします。*/
			fprintf(stderr,"ERROR: invalid value as height(%s)\n[[Abort]]\n",buf);
			return 1;
		}
		/*無事に処理が終わったら解放*/
		free(buf);
	}
	/*数値が意味をなすか確認*/
	if(height<=0.0)
	{
		/*身長は正の値だと思われるため，0以下の場合Abortします。0除算対策も兼ねています。*/
		fprintf(stderr,"ERROR: invalid value as height(%2.2lf)\n[[Abort]]\n",height);
		return 2;
	}

	/*身長とほぼ同じ処理を体重に対しても行います。*/
	if(flag&FLAG_W)
	{
		buf = (char *)malloc(sizeof(char)*BUF_SIZE);
		if(buf==NULL)
		{
			fprintf(stderr,"Memory allocation failed! [[Abort]]\n");
			return -1;
		}
		memset(buf,0,sizeof(char)*BUF_SIZE);
		fprintf(stdout,"Weight[kg]:");
		if(fgets(buf,BUF_SIZE,stdin) == NULL)
		{
			fprintf(stderr,"Reading input failed! [[Abort]]\n");
			free(buf);
			return -1;
		}
		if(strchr(buf,'\n') == NULL)
		{
			while(getc(stdin) != '\n');
		}else{
			*( buf+(strlen(buf)-1) ) = 0;
		}
		errno^=errno;
		weight=strtod(buf,(char **)NULL);
		if(errno!=0)
		{
			fprintf(stderr,"ERROR: invalid value as weight(%s)\n[[Abort]]\n",buf);
			return 1;
		}
		free(buf);
	}
	if(weight<=0.0)
	{
		fprintf(stderr,"ERROR: invalid value as weight(%2.2lf)\n[[Abort]]\n",weight);
		return 8;
	}

	/*pow関数使うまでもないと判断*/
	bmi = weight/(height*height);

	/*計算式と結果を開示します。*/
	fprintf(stdout, "Your BMI is %2.2lf\n"
			"%2.2lf/(%2.2lf)^2\n",bmi,weight,height);
	return 0;
}
