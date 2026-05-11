#include<stdio.h>
#include<string.h>

int main()
{
  char str[100];
  int n,i,count[10]={0};
  
  
  printf("文字列を入力してください(長さ100以下）\n");
  scanf("%s",str);
  for(n=0;n<strlen(str);n++)
    for(i=0;i<10;i++){
    if(str[n]==48+i)
        {
	  count[i]=count[i]+1;
	    }
    }
     
  for(i=0;i<10;i++)
    printf("%d は　%d個含まれています\n",i,count[i]);
    
  return 0;
}
