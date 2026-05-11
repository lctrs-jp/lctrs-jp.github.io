#include<stdio.h>
#include<string.h>

int main ()
{
  char s[100];
  int a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
  int i,j,k;
 a0=0;
 a1=0;
 a2=0;
 a3=0;
 a4=0;
 a5=0;
 a6=0;
 a7=0;
 a8=0;
 a9=0;
 printf("文字を入力してください\n");
    fgets(s,100,stdin);
    k=strlen(s);
  for(i=0;i<k;i++){
    if(s[i]=='0')
      a0++;
    else if(s[i]=='1')
      a1++;
    else if(s[i]=='2')
      a2++;
    else if(s[i]=='3')
      a3++;
    else if(s[i]=='4')
      a4++;
    else if(s[i]=='5')
      a5++;
    else if(s[i]=='6')
      a6++;
    else if(s[i]=='7')
      a7++;
    else if(s[i]=='8')
      a8++;
    else if(s[i]=='9')
      a9++;
}
printf("0は%d個\n",a0);
printf("1は%d個\n",a1);
printf("2は%d個\n",a2);
printf("3は%d個\n",a3);
printf("4は%d個\n",a4);
printf("5は%d個\n",a5);
printf("6は%d個\n",a6);
printf("7は%d個\n",a7);
printf("8は%d個\n",a8);
printf("9は%d個\n",a9);

  return 0;
}
    
