#include <stdio.h>

int main()
{
  int i;
  char x[100];
  int countb[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int counts[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int count[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  printf("文字を入力してください。（長さ100以下）\n");
  fgets(x,100,stdin);

  for(i=0;x[i]!='\0';i++){
    if('A'<=x[i]&&x[i]<='Z'){
      countb[x[i]-'A']++;
    }
    if('a'<=x[i]&&x[i]<='z'){
      counts[x[i]-'a']++;
    }
    count[x[i]-'A']=countb[x[i]-'A']++counts[x[i]-'a'];
  }

  for(i=0;i<27;i++){
    int max;
    if(max<count[i]){
      max=count[i];
    }
  }
    printf("最頻出文字は%s・%s\n",x[i]-'A',x[i]-'a');
    printf("出現回数は%d\n",count[x[i]-'A']);
      return 0;
}
