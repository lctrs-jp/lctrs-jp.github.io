#include <stdio.h>

#define SLIM 18.5
#define FAT 25
#define VERYFAT 30
//#define DEBUG

/* BMIを計算する関数 */
float calcBMI(void);
/* BMI値を判定する関数 */
void checkBMI(float bmi);

int main(void)
{
  float bmi = 0;

  // BMIを計算
  bmi = calcBMI();

#ifdef DEBUG
  printf("BMI = %.2f\n", bmi);
#endif

  // BMIを判定
  checkBMI(bmi);

  return 0;
};

float calcBMI(void)
{
  float height = 0;
  float weight = 0;

  // 身長を入力
  printf("input your height (m)\n");
  printf(">> ");
  scanf("%f", &height);

  // 体重を入力
  printf("input your weight (kg)\n");
  printf(">> ");
  scanf("%f", &weight);

  // BMIを計算
  return (weight/(height*height));
};

void checkBMI(float bmi)
{
  printf("あなたは\"");

  if( bmi <= 0 ){		// 人外
    printf("人外");
  }else if( bmi < SLIM ){	// やせ
    printf("やせ");
  }else if( bmi < FAT ){	// 標準
    printf("標準");
  }else if( bmi < VERYFAT ){	// 肥満
    printf("肥満");
  }else{			// 高度肥満
    printf("高度肥満");
  }

  printf("\"です。\n");
};
