#include <stdio.h>
#include <string.h>

void counter(char str[]);


int main(void)
{

	int i=0;
	char x[1000];

printf("文字を入力してください\n");
fgets(x,1000,stdin);

counter(x);

return 0;

}

// 文字をカウントするcounter関数
void counter(char str[])
{
	int i=0,x=0,y=0;
	int a[10000];
	
	for(i=0;i<26;i++){
		a[i]=0;
	
	for(i=0;i<strlen(str);i++)
		switch(str[i]){
			case'a':
			case'A':
			a[0]++;
			break;
			case'b':
			case'B':
			a[1]++;
			break;
			case'c':
			case'C':
			a[2]++;
			break;
			case'd':
			case'D':
			a[3]++;
			break;
			case'e':
			case'E':
			a[4]++;
			break;
			case'f':
			case'F':
			a[5]++;
			break;
			case'g':
			case'G':
			a[6]++;
			break;
			case'h':
			case'H':
			a[7]++;
			break;
			case'i':
			case'I':
			a[8]++;
			break;
			case'j':
			case'J':
			a[9]++;
			break;
			case'k':
			case'K':
			a[10]++;
			break;
			case'l':
			case'L':
			a[11]++;
			break;
			case'm':
			case'M':
			a[12]++;
			break;
			case'n':
			case'N':
			a[13]++;
			break;
			case'o':
			case'O':
			a[14]++;
			break;
			case'p':
			case'P':
			a[15]++;
			break;
			case'q':
			case'Q':
			a[16]++;
			break;
			case'r':
			case'R':
			a[17]++;
			break;
			case's':
			case'S':
			a[18]++;
			break;
			case't':
			case'T':
			a[19]++;
			break;
			case'u':
			case'U':
			a[20]++;
			break;
			case'v':
			case'V':
			a[21]++;
			break;
			case'w':
			case'W':
			a[22]++;
			break;
			case'x':
			case'X':
			a[23]++;
			break;
			case'y':
			case'Y':
			a[24]++;
			break;
			case'z':
			case'Z':
			a[25]++;
		
		}

		 for(x=1;x<26;++x)
    for(y=26-1;y>=x;--y){
      //compare//
      if (a[y-1]>a[y]){
	//switch//
	i=a[y-1];
	a[y-1]=a[y];
	a[y]=i;
      }
    }

	printf("最頻出文字数は%d\n",a[25]);
	
	for(i=0;i<26;i++){
	printf("%d個含まれています\n",a[i]);
	
	}
	return ;

}