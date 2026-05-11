#include<stdio.h>

int main()
{int i,j;
printf("数字を入力してください。");
 scanf("%d",&i);
    while(i!=1)
    /*偶数*/
      {    j=i%2;
 if(j==0)
      {i=i/2;}
  /*奇数*/
    if(j==1)
      {i=i*3+1;}
	printf("%d\n",i);}
		return 0;
}
