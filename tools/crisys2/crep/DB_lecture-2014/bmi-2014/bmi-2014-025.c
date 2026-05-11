#include <stdio.h> /* BMIを計算するプログラム */

int main()
{
  double height; /* 身長 */
  int weight; /* 体重 */

  printf("身長[m]を入力してください(例1.60): ");
  scanf("%lf", &height); /* 身長情報を取込 */
  printf("体重[kg]を入力してください(例60): ");
  scanf("%d", &weight); /* 体重情報を取込 */

  printf("あなたのBMIは %lf です。\n" , weight / ( height * height ) ); /* 計算結果を表示 */
  return 0;
}
