 #include <stdio.h>

int main(void)
{
  float temp[7], min, max, avg, var, dece, mid, tmp;
  int days, i;
 
  days = 7;
 
    for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
  } 
  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++)
    avg =avg + temp[i];
  printf("平均気温: %f\n", avg /days);
  /* 最高気温と最低気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i] )
      min = temp[i];
    if (max < temp[i] )
      max = temp[i];
  }

  printf("最高気温: %f\n", min);
  printf("最低気温: %f\n", max);

  /* 標準偏差をもとめる*/

  var = 0;
  for (i = 0; i< days; i++)
    var = (temp[i] - avg) * (temp[i] - avg);
  printf("標準偏差: %f\n", var);
 
 /* 分散を求める */
  dece = 0;
  for (i = 0; i< days; i++)
    dece = var * var;
  printf("分散: %f\n", dece);

  /*中間値を求める */
  mid = 0;
  tmp = 0;
  for (i = 0; i< days; i++)
    {
      if(temp[i] >temp[i + 1])
	{
	  tmp = temp[i];
	  temp[i] = temp[i + 1];
	  temp[i + 1] = tmp;
}
}
  mid = temp[(days - 1) / 2];
  printf("中間値: %f\n", mid); 
 return 0;
}
