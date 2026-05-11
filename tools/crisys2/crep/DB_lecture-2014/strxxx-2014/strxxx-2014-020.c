/*********************************************
* mystring.c
* *********
* ******* *********
* -----更新履歴-----
* 2014/10/28 20:57 作成
* クソテスト追加
*********************************************/

#include <stddef.h>
#include <stdio.h>
#include <string.h>

/*テスト用データ*/
static char len[][2][64]={
	{"abcdef\0","6"},
	{"CamelStyle\0","10"},
	{"!#%&(1234!#\0","11"},
	{"There\tare\tsome\ttabs.\0","20"},
	{"__END__\0",""}
};

static char cpy[][2][64]={
	{"abc\0",""},
	{"CamelStyle\0",""},
	{"ぜんかくもじ\0",""},
	{"記\t号\t類\0",""},
	{"__END__\0",""}
};

static char cat[][3][64]={
	{"abc\0","def\0","abcdef\0"},
	{"CamelStyle\0","__asd\0","CamelStyle__asd\0"},
	{"ぜんかくもじ\0","です\0","ぜんかくもじです\0"},
	{"記\t号\t類\0","e\ts\nt\0","記\t号\t類e\ts\nt\0"},
	{"__END__\0","",""}
};

int mystrlen(char* src){
	int c=0;

	while(*(src+c)){c++;}
	return c;
}

/*以後，メモリが十分にあることを確認せず行ってはいけない処理*/
char*  mystrcpy(      char* dest, char* src){
	unsigned int i=0;
	/*頭からNULLまでコピー*/
	for(i=0; *(src+i)!=0; i++){
		*(dest+i) = *(src+i);
	}
	/*NULLを追加*/
	*(dest+i)=0;
	return dest;
}

char*  mystrcat(      char* dest, char* src){
	unsigned int i,src_len,dst_len;
	dst_len=strlen(dest);
	src_len=strlen(src);
	for(i^=i; i<src_len; i++){
		*(dest+dst_len+i) = *(src+i);
	}
	*(dest+dst_len+src_len)=0;
	return dest;
}

/*テスト関数*/
int test_len(void)
{
	int i = 0;
	char ret[32];
	while(strcmp(len[i][0],"__END__"))
	{
		sprintf(ret,"%d",mystrlen(len[i][0]));
		if (strcmp(len[i][0],ret)){
			printf("lenテスト%d は成功\n",i+1);
		}else{
			printf("lenテスト%d は失敗!!\n",i+1);
			printf("  作った関数の出力: %s\n",ret);
			printf("  期待される結果  : %s\n",len[i][1]);
			return 1;
		}
	i++;
	}
	return 0;
}

int test_cpy(void)
{
	int i = 0;
	while (strcmp(cpy[i][0],"__END__")){
		mystrcpy(cpy[i][1],cpy[i][0]);
		if (!strcmp(cpy[i][0],cpy[i][1])){
			printf("cpyテスト%d は成功\n",i+1);
		}else{
			printf("cpyテスト%d は失敗!!\n",i+1);
			printf("  作った関数の出力: %s\n",cpy[i][0]);
			printf("  期待される結果  : %s\n",cpy[i][1]);
			return 1;
		}
		i++;
	}
	return 0;
}

int test_cat(void)
{
	int i = 0;
	while (strcmp(cat[i][0],"__END__")){
		mystrcat(cat[i][0],cat[i][1]);
		if (!strcmp(cat[i][0],cat[i][2])){
			printf("catテスト%d は成功\n",i+1);
		}else{
			printf("catテスト%d は失敗!!\n",i+1);
			printf("  作った関数の出力: %s\n",cat[i][0]);
			printf("  期待される結果  : %s\n",cat[i][2]);
			return 1;
		}
		i++;
	}
	return 0;
}

int main(int nCmd, char* cCmd[]){
	test_len();
	test_cpy();
	test_cat();
	return 0;
}
