#include<stdio.h>

void mystrcat(char c1[],char c2[])
{
	int i, j;
	for(i=0; c1[i]!=0; i++);
	for(j=0; c2[j]!=0;j++)
		c1[i+j]=c2[j];
	c1[i+j] = '\0';
}

int mystrlen(char ch[])
{
	int i;
	for(i=0;ch[i]!='\0';i++);
	return i;
}

void mystrcpy(char c1[], char c2[])
{
	int i;
	for(i=0;c2[i]!=0;i++)
		c1[i]=c2[i];
	c1[i]='\0';
}

int mystrcmp(char c1[],char c2[]){
	int i;
	for(i = 0;c1[i]==c2[i];i++){
		if(c1[i]==0)break;
	}
	return c1[i]-c2[i];
}

int main(void)
{
	char str1[80], str2[80];
	int i;
	
	printf("第一の文字列を入力してください:");
	gets(str1);
	printf("第二の文字列を入力してください:");
	gets(str2);
	
	printf("%sは%d文字の長さです\n", str1, mystrlen(str1));
	printf("%sは%d文字の長さです\n", str2, mystrlen(str2));
	
	i = mystrcmp(str1, str2);
	if(!i)
		printf("文字列は等しい\n");
	else if(i < 0)
		printf("%sは%sより小さい\n", str1, str2);
	else
		printf("%sは%sより大きい\n", str1, str2);
	
	if((mystrlen(str1) + mystrlen(str2)) < 80){
		mystrcat(str1, str2);
		printf("%s\n", str1);
	}
	
	mystrcpy(str1, str2);
	printf("%s %s\n", str1, str2);
		
	return 0;
}