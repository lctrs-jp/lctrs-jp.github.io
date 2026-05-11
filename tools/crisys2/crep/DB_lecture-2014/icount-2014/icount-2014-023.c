#include <stdio.h>

int main()

{

  char N[100];
  int X[10]={0,0,0,0,0,0,0,0,0,0};
  int i  ;
    printf("数字列を入力してください(長さ100以下): ");
    scanf("%s" , N);

  for(i=0;N[i]!='\0';i++)
     if(N[i]>='0' && N[i]<='9')
       {  X[N[i]-'0']++;
	}

	

  for (i=0; i<10; i++) 
    printf("%dは%d個含まれています\n",i,X[i]);
  return 0;
}
