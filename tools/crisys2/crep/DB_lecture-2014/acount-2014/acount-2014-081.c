#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upcase(char*);
int chr_cnt(char*,char); /* 文字列 str 中の文字 c の数を返す関数 */

int main(){
	signed int table[26], max_count;
	unsigned char c;
	char buf[128];

	c=0;
	max_count=-1;

	memset(buf,  0,sizeof(char)*128);

	fprintf(stdout,"文字列を入力してください(最大127文字):");
	if(fgets(buf,128,stdin) == NULL){
		fprintf(stderr,"入力値の読み込みに失敗したので終了します。\n");
		return -2;
	}

	/*万一stdinに入力が残った時の後始末*/
	if(strchr(buf,'\n') == NULL){
		while(getc(stdin) != '\n');
	}else{
		*( buf+(strlen(buf)-1) ) = 0;
	}

	/*大文字・小文字を区別しないので、カウント対象の文字を
	すべて大文字にする*/
	upcase(buf);

	/*カウントテーブルを初期化*/
	memset(table,0,sizeof(int)*26);

	/*文字とその出現頻度を問い合わせる*/
	for(c=0;c<=('Z'-'A');c++){
		table[c]=chr_cnt(buf,'A'+c);
	}

	/*最頻出「回数」を検索。
	※(数値の位置)==(文字)なので、ソートしてはいけない。*/
	for(c=0;c<26;c++){
		if( table[c] > max_count){
			max_count=table[c];
		}
	}

	/*入力された文字列にアルファベットが含まれていない場合、
	すべてのカウントが0となる。
	　これらを「最頻出文字」として表示するのはよくないので、
	max_countが0のとき、表示を改める。*/

	if(max_count!=0){
		fprintf(stdout,"最頻出文字は");
		for(c=0;c<26;c++){
			if(table[c]==max_count){
				fprintf(stdout," %c",'A'+c);
			}
		}
		fprintf(stdout,"\n出現回数は%d回\n",max_count);
	}
	/*アルファベットが一文字も入っていないとき*/
	else{
		fprintf(stdout,"アルファベットはありませんでした。\n");
	}

	return 0;
}

void upcase(char src[])
/*文字列中の小文字を大文字に変換する関数
ただし，変換するのは a から z までのアルファベットだけで
それ以外の文字・記号は変更しない*/
{
	size_t l_src, i;
	l_src^=l_src;
	i^=i;
	l_src = strlen(src);
	for(i=0; i<l_src; i++){
		if( 0x61<=src[i] && src[i]<=0x7A){
			src[i]-=0x20;
		}
	}
	return;
}

int chr_cnt(char src[],char c)
/*文字列 str 中の文字 c の数を返す関数
大文字と小文字は区別する*/
{
	unsigned int count, i;
	size_t l_src;
	count^=count;
	l_src=strlen(src);
	for(i^=i;i<l_src;i++){
		if(src[i] == c){
			count++;
		}
	}
	return count;
}

