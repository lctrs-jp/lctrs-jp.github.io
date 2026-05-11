#include <stdio.h>


int main()
{
  int n; /* 体重を表す変数 */
  float m; /* 身長を表す変数 */

  scanf("%d", &n );
  scanf("%f", &m );

  printf("%d / (%f * %f) = %f\n", n, m, m, n/(m*m) );
  return 0;
}
