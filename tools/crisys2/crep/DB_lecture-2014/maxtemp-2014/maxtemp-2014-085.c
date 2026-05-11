#include <stdio.h>
#include <math.h>
int main(void)
{
  float avg, t, sig, temp[31], max, min;
  int day;
  int i, j, a;
  printf("入力する７日間の最初の日にちを入力してください。\n");
    scanf("%d", &day);

    for (i =0; i + day  <= day + 6; i++) {
      printf("%d日の最高気温℃を入力してください。", i + day );
      scanf("%f", &temp[i]);
    }

    /*平均*/
    avg = 0;
    for (i = 0; i + day <= day + 6; i++)
      avg = avg + temp[i];
    printf ("平均気温：%f\n", avg / 7);

    /*最高気温の最大値と最小値*/
    min = 999;
    max = -999;
    for (i = 0; i + day <= day + 6; i++){
     if (min > temp[i])
	 min = temp[i];
     if (max < temp[i])
	 max = temp[i];
	 }
      printf("最高気温の最大値：%f\n", min);
     printf("最高気温の最低値：%f\n", max);

	 /*標準偏差と分散*/
     sig = 0;
     for (i = 0; i + day <= day + 6; i++){
	   sig = sig + (temp[i] - avg / 7) * (temp[i] - avg / 7);
     }
      printf("最高気温の分散：%f\n", sig / 7);
      printf("最高気温の標準偏差：%f\n", sqrt(sig));

	 /*中間値*/
for (a = 0; a + day <= day + 6; a++)
	   for(j = 6; j >= a; --j){
	   if(temp[j - 1] > temp[j]){
		   t = temp[j - 1];
		   temp[j - 1] = temp[j];
		   temp[j]=t;
	   }
	   }
		   printf("最高気温の中間値：%f\n", temp[3]);

	   return 0;
}
