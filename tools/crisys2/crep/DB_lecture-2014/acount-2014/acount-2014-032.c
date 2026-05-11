#include<stdio.h>
#include<string.h>

void times(char str[]);

int main(){
	
	int i;
	char str[40];
	
	//文字列の入力
	printf("入力：");
	fgets(str,20,stdin);
	
	//出現回数を調べる関数timesに文字列を渡す
	for(i=0;i<str[i];i++){
		times(&str[i]);
	}
	
	printf("プログラムを終了します。\n");
	
	return 0;
}


void times(char str[]){
	int s,t,u,i,j;
	int count;
	
		for(i=0;i<str[i];i++){
			s = str[i];
			if((u==str[i])||(u==str[i]+32)||(u==str[i]-32)) return;   //すでに数えた文字は評価しない
		  	//文字列が大文字か小文字か評価
			if(((s>=65)&&(s<=90))||((s>=97)&&(s<=122))){ 
				for(j=0;j<str[j];j++){
					if(s==str[j]) count++;   //同一の文字を数える
					if((s==str[j]+32)||(s==str[j]-32)) count++;   //大文字小文字の区別をなくす
				}
					if((u!=str[i])&&(t>count)) return;
					if(count>t){
					t = count;
					printf("出現回数の多い文字は%cで%d回\n",str[i],t);
					u = str[i];   //数えた文字を記憶
					t = 0;
					count=0;
					return;
					}
			}
		}
	return;
}