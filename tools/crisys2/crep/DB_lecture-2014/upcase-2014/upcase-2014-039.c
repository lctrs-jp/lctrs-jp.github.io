#include<stdio.h>
#include<string.h>

void upcase(char str[]);

int main(){
	
	int i;
	char str[40];
	
	//文字列の入力
	printf("入力：");
	fgets(str,20,stdin);
	
	printf("%s  ->",str);
	for(i=0;i<str[i];i++){  //関数upcaseに文字列を渡す
		upcase(&str[i]);
		}
		printf("%s\n",str);   //変換後の文字列を表示
	
	return 0;
}

void upcase(char str[]){
	int i;
	
	for(i=0;i<str[i];i++){	
		if((str[i]>=97)&&(str[i]<=122)){   //ASCIIコードより大文字に変換
			str[i] -= 32;
		}	
		}
		return;
}