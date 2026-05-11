#include <stdio.h>  /* BMIを計算するプログラム診断つき */

int main()
{
  double BMI_calc(double height, int weight);  /* プロトタイプ宣言 */
  double height;  /* 身長 */
  int weight;  /* 体重 */
  double BMI;  /* BMI */

  printf("身長[m]を入力してください(例1.60): ");
  scanf("%lf", &height);  /* 身長情報を取込 */
  /* 身長の入力を正の値に制限 */
  while ( height < 0 ){
    printf("身長は正でなければなりません。\n");
    printf("身長[m]を入力してください(例1.60): ");
    scanf("%lf", &height);
  }

  printf("体重[kg]を入力してください(例60): ");
  scanf("%d", &weight);  /* 体重情報を取込 */
  /* 体重の入力を正の値に制限 */
  while ( weight < 0 ){
    printf("体重は正でなければなりません。\n");
    printf("体重[kg]を入力してください(例60): ");
    scanf("%d", &weight);  /* 体重情報を取込 */
  }

  BMI = BMI_calc(height, weight);  /* BMIの計算関数へ */

  printf("あなたのBMIは %lf です。\n", BMI );  /* 計算結果を表示 */

  /* BMIの判定を出力 */
  if( BMI >= 30 )
    printf("高度の肥満です。\n") ;
  if ( BMI >= 25 && BMI < 30 )
    printf("肥満です。\n");
  if ( BMI >= 18.5 && BMI < 25 )
    printf("標準です。\n");
  if ( BMI > 0 && BMI < 18.5 )
    printf("やせています。\n");

  return 0;
}

double BMI_calc(double height, int weight)  /* BMIを計算する関数 */
{
  double BMI = weight / ( height * height) ;
  return BMI;
}
