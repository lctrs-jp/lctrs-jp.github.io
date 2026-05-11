#include<stdio.h>

int main(void)
{
	int item[100];
	int a, b, c, t;
	int count;
	
	//数値を読み取る
	printf("数値をいくつ入力しますか？\n");
	scanf("%d", &count);
	printf("数値を%d個入力してください\n",count);
	
	for(a=0;a<count;a++){
		printf("%d ) ", a+1);
		scanf("%d", &item[a]);
		}	
	
	//バブルソート
	for(a=1;a<count;a++){
		for(b=count-1;b>=a;b--){
			//隣接する要素を比較
				if(item[b-1]>item[b]){//要素を交換する
					for(c=0;c<count;c++){
					printf("%d  ",item[c]);
					}
					t = item[b-1];	
					item[b-1] = item[b];
					item[b] = t;
					printf("\n");
			}
		}
	}
	
	//整列後のリストを表示
	printf("バブルソートの結果\n");
	for(t=0;t<count;t++){
		printf("%d ", item[t]);
		}
		printf("\n");
	return 0;
}			