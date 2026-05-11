#include<stdio.h>

int main()
{
  char num[100];
  int count[10]={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
  int i,j,k,l;

  printf("数字列を入力してください（長さ100以下） :");
  fgets(num,100,stdin);

  for(i=0 ; num[i] !='\0' ;i++){
    k=num[i]-48;
    if(k>=0 && 9>=k){
      count[k]=count[k]+1;
    }
  }

  for(i=0;i<10;i++){
    printf("%d は %d 個含まれる\n" , i , count[i]);
  }

  return 0;
}
