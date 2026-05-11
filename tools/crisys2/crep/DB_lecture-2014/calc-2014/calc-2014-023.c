#include <stdio.h>
#include <math.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a,int b);
int cmp(void* a,void* b);

int (*p[5]) (int x, int y);

int main()
{
	int result;
	int i, j, op;

	result^=result;
	i^=i; j^=j;op^=op;

	p[0] = sum;
	p[1] = subtract;
	p[2] = mul;
	p[3] = div;
	p[4] = power;

	printf("二つの数を入力してください：");
	scanf("%d%d", &i, &j);
	printf("0加算\t1減算\t2乗算\n3除算\t4冪算\t5比較のテスト\n");
	do {
		printf("演算番号:");
		scanf("%d",&op);
	}while((op<0)||(op>5));

	if(op==5){
		int sort[100];
		/*乱数をセット*/
		srandom((unsigned int)(subtract(i,j)));
		for(op=0; op<100; op++){
			sort[op] = random();
		}

		/*ソート！*/
		qsort(sort,100,sizeof(int),cmp);

		printf("1st\t2nd\n3rd\t4th\nの順に表示します\n");

		/*ソート後を表示*/
		for(op=0; op<100; op+=2){
			printf("%10d\t%10d\n",sort[op],sort[op+1]);
		}

		/*オペコードを復元*/
		op=5;
	}else{
		result = (*p[op])(i,j);
		printf("Result:%d\n",result);
	}

	return 0;
}

int sum(int a, int b){
	return a+b;
}

int subtract(int a,int b){
	return a-b;
}

int mul(int a,int b){
	return a*b;
}

int div(int a,int b){
	if(b){
		return a/b;
	}else{
		return 0;
	}
	return -1;
}

int power(int a,int b){
	return pow(a,b);
}

int cmp(void* a, void* b){
	return *(int*)(a) - *(int*)(b);
}
