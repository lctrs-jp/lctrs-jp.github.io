int main()
{
  float weight, height; //体重と身長を表す変数

  printf("体重(kg)を入力してください\n");
  scanf("%f", &weight);

  printf("身長(m)を入力してください\n");
  scanf("%f", &height);

  printf("あなたのＢＭＩは　%f\n", weight / (height * height) );

  return 0;
}