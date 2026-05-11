#include <stdio.h>
#include <string.h>

void counter(char a[]);


int main(void)
{

	int i=0;
	char x[1000];

printf("数値を入力してください\n");
fgets(x,1000,stdin);

counter(x);

return 0;

}

// 数字をカウントするcounter関数
void counter(char a[])
{
	int i;
	int zero=0,one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0;
	for(i=0;i<strlen(a);i++)
		switch(a[i]){
			case'0':
			zero++;
			break;
			case'1':
			one++;
			break;
			case'2':
			two++;
			break;
			case'3':
			three++;
			break;
			case'4':
			four++;
			break;
			case'5':
			five++;
			break;
			case'6':
			six++;
			break;
			case'7':
			seven++;
			break;
			case'8':
			eight++;
			break;
			case'9':
			nine++;
		
		}

	printf("0は%d個含まれています\n",zero);
	printf("1は%d個含まれています\n",one);
	printf("2は%d個含まれています\n",two);
	printf("3は%d個含まれています\n",three);
	printf("4は%d個含まれています\n",four);
	printf("5は%d個含まれています\n",five);
	printf("6は%d個含まれています\n",six);
	printf("7は%d個含まれています\n",seven);
	printf("8は%d個含まれています\n",eight);
	printf("9は%d個含まれています\n",nine);
	

	return ;

}