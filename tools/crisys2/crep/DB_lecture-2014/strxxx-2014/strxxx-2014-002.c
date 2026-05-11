#include<stdio.h>
#include<string.h>

void mystrcpy(char trg[], char src[]){
int s,t;
  for (s=0;trg[s];s++){
    trg[s] = ' ';
}
for(t=0;src[t];t++){
	trg[t] = src[t];
	}

}

void mystrcat(char trg[],char src[]){
	int s,t,r;
	for(s=0;trg[s];s++){
	r = s;
	}
	r= r+1;
	for(t=0;src[t];t++){
	trg[r+t] = src[t];
	}
}

int mystrlen(char trg[]){
	int len;
	int i;
	for(i=0;trg[i];i++){
		len++;
	}
	return len;
}

int mystrcmp(char trg[],char src[]){
	int lena,lenb;
	int s,t;
	for(s=0;trg[s];s++){
		lena++;
	}
	for(t=0;src[t];t++){
		lenb++;
	}
	return lena-lenb;
}

int main(){

char str1[80];
char str2[80];
int i;

//文字列の入力
printf("第一の文字を入力してください：");
gets(str1);
printf("第二の文字を入力してください：");
gets(str2);

//文字列の長さ
printf("%s は　%d 文字の長さです\n",str1 ,mystrlen(str1));
printf("%s は　%d 文字の長さです\n",str2 ,mystrlen(str2));

//文字列を比較
i = mystrcmp(str1,str2);
if(i == 0){
	printf("文字列は等しい\n");
}else if(i<0){
	printf("%s は %s より小さい\n",str1 ,str2);
	}else if(i>0){
		printf("%s は %s より大きい\n",str1 ,str2);
		}
		
//十分なスペースがあればstr2をstr1の最後に連結する
if((mystrlen(str1) + mystrlen(str2) <80)){
	mystrcat(str1,str2);
		printf("%s\n",str1);
		}
		
//str2をstr1にコピーする
mystrcpy(str1,str2);
printf("%s %s\n",str1 ,str2);

return 0;

}