#include<stdio.h>

int chr_cnt(char trg[], char c);

int main()
{
	int i , max , count[100];
	for(i=0 ; i < 100 ; i++ )
	count[i] = 0;
	
	char str[102] , c ;
	
	
	
	printf("文字列を入力してください（長さ100以下）");
	fgets(str, 102, stdin);
	
	//大文字を小文字に変換
	i = 0;
	while(str[i] != 0)
	{
		if(65 <= str[i] && str[i] <= 90)
		str[i] = str[i] + 32;
		
		i++;
	}
	
	//文字列の中のaからzの数を数える
	i=0;
	while(i < 26)
	{
		count[i] = chr_cnt(str, 'a' + i );
		i++;
	}
	
	//数えたものの最大値を出す
	max = 0;
	i = 0;
	while(i < 26)
	{
		if(max < count[i])
		max = count[i];
		i++;
	}
	
	//printf("最頻出文字は %c " , max
	printf("出現回数は %d 回" , max);
	
	

	
	

		
	
	
		
	
	return 0;
}




int chr_cnt(char trg[],char c)
// 文字列 trg 中の文字 c の数を返す関数
// 大文字と小文字は区別する
{
	int i,count;
	
	count=0;
	i=0;
	while(trg[i] !=0){
		if(trg[i]==c)
		count=count+1;
		
		i++;
	}
	
	return count;
}


