#include <stdio.h>

float bmi(float x, float y);
void bmiscore(float c);

int main(void)
{
  float wei; /*体重を受け取る*/
  float hei; /*身長を受け取る*/
  float i;
  int j;

  do{
    printf("身長を入力してください(m):");
    scanf("%f", &hei);
    printf("体重を入力してください(kg):");
    scanf("%f", &wei);
    if (hei > 4){
      printf("単位を確認してください、あっているなら１を、間違っているなら２を入力してください:\n");
      scanf("%d", &j);
      switch (j){
      case 1:
	break;
      case 2:
	hei = -1;
	break;
      default:
	printf("予期せぬ数値です、最初からやり直してください");
	return 0;
      }
    }

  } while ((hei <= 0) || (wei <= 0)); /*どちらかが０以下のとき条件式が真でループする*/

  i = bmi(hei, wei);

  printf("あなたのBMIは、%fです\n", i);
  bmiscore(i);

  return 0;
}

float bmi(float x, float y) /*BMIを算出する*/
{
  float z;
  z = y / (x * x);
  return z;
}

void bmiscore(float c) /*BMIに基ずき、肥満度を表示する*/
{
  if (c < 18.5){ /*18.5未満*/
    printf("あなたは痩せ型です\n");
  } else if (c >= 18.5 && c < 25){ /*18.5以上、25未満*/
    printf("あなたは標準です\n");
  } else if (c >= 25 && c < 30){ /*25以上、30未満*/
    printf("あなたは肥満です\n");
  } else if (c >= 30){ /*30以上*/
    printf("あなたは高度の肥満です、病院に健康診断に行きましょう\n");
  }
  return ;
}
