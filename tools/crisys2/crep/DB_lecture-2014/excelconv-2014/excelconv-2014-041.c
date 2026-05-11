#include<stdio.h>
#include<math.h>

void rev(long *rt2, long i2, long j2, char *mot2);
long excv(char *mot);

int main(int argc, char *argv[]){
	
	printf("%ld\n",excv(argv[1]));
	return;
}

void rev(long *rt2, long i2, long j2, char *mot2){
	if((long)mot2 - i2 + 1){
		(*rt2) += (long)(*mot2 - 'A' + 1) * powl(26, j2 - (long)mot2);
		mot2--;
		rev(rt2, i2, j2, mot2);
	}
}//解説はexcv関数の28行目を参照

long excv(char *mot){
	long rt = 0;//rtを返す
	long i = (long)mot;//最初のポインタ
	for(; *(mot + 1) >= 'A' && *(mot + 1) <= 'Z'; mot++);//motを最後のポインタに
	long j = (long)mot;//最後のポインタ
	rev(&rt, i, j, mot);//再帰関数revに代入
	//for(; (long)mot - i + 1; mot--) rt += (long)(*mot - 'A' + 1) * powl(26, j - (long)mot);
	return rt;
}