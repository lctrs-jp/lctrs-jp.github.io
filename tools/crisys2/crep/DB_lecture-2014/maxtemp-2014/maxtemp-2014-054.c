#include<stdio.h>
#include<math.h>

int main()
{
  int i, j;
  float temp[7], min, max, avg, sdd, vrc[7], mdn;

  /*for関数をうまく使う方法が思い浮かびませんでした*/
  printf("日曜日の最高気温を入力してください:");
  scanf("%f",&temp[0]);
  printf("月曜日の最高気温を入力してください:");
  scanf("%f",&temp[1]);
  printf("火曜日の最高気温を入力してください:");
  scanf("%f",&temp[2]);
  printf("水曜日の最高気温を入力してください:");
  scanf("%f",&temp[3]);
  printf("木曜日の最高気温を入力してください:");
  scanf("%f",&temp[4]);
  printf("金曜日の最高気温を入力してください:");
  scanf("%f",&temp[5]);
  printf("土曜日の最高気温を入力してください:");
  scanf("%f",&temp[6]);

  avg = 0;
  for (i = 0; i < 7;i++)
    avg = avg + temp[i];
  printf("平均気温:%f\n", avg / 7);

  min = 200.0;
  max = 0.0;
  for (i = 0; i < 7; i++){
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }
  printf("一週間の最高気温の最小値:%f\n",min);
  printf("一週間の最高気温:%f\n",max);

  for(i = 0;i < 7; i++){
    vrc[i] = (avg / 7 - temp[i]) * (avg / 7 - temp[i]);
      }
  for(i = 0;i < 7;i++)
    sdd = sdd + vrc[i];
  printf("標準偏差は:%f\n",sqrt(sdd / 7));
  printf("分散は:%f\n",sdd / 7);

  for(i = 1; i < 7;++i)
    for (j = 7 - 1;j >= i; --j){
      if (temp[j - 1] > temp[j]){
	mdn = temp[j = 1];
	temp[j - 1] = temp[j];
	temp[j] = mdn;
      }
    }
  printf("中央値は:%f\n",temp[3]);

  return 0;
}
