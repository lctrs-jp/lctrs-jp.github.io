#include<stdio.h>
#include<math.h>

int main(){
 int a;
  	 
  	printf("数値を入力してください（2以上３＊２^53以下） ：　");
  	while(1){
 	scanf("%d",& a);
 		if((a<=2)||(a>=3*pow(2,53))){   //エラー表示
 			printf("範囲外です。\n");
 			break;		
 		}
 		printf("%d -> ",a);
 		while(1){
 			if(a%2==0){   //偶数ならば2で割る
 				a = a / 2;
 				printf("%d -> ",a);	
 			}else{   //奇数ならば3かけて1加える
 				a = a * 3 + 1;
 				printf("%d -> ",a);
 			}
 			if(a==1){   //1になれば抜け出す
 				printf("\n");
 				break;
 			}
 		}
 		break;
 	}
 	printf("プログラムを終了します。\n");
 	return 0;
 }