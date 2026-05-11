#include<stdio.h>


int main(void)
{

  int a ,b=0, c=0, d=0 ,e=0, f=0, g=0, h=0, i=0, j=0, k=0;
  printf("９９文字以内で数字を入力　確定はctrl+dを２回\n");


char s[100];
fgets(s, 100,stdin);
 printf("\n");

for(a=0;s[a]!='\0';a++)
  {
  if(s[a]=='0')
    b++;
  else if(s[a]=='1')
    c++;
  else if(s[a]=='2')
    d++;
  else if(s[a]=='3')
    e++;
  else if(s[a]=='4')
    f++;
  else if(s[a]=='5')
    g++;
  else if(s[a]=='6')
    h++;
  else if(s[a]=='7')
    i++;
  else if(s[a]=='8')
    j++;
  else 
    k++;
    }
 
printf("0の個数:%d\n",b);
printf("1の個数:%d\n",c);
printf("2の個数:%d\n",d);
printf("3の個数:%d\n",e);
printf("4の個数:%d\n",f);
printf("5の個数:%d\n",g);
printf("6の個数:%d\n",h);
printf("7の個数:%d\n",i);
printf("8の個数:%d\n",j);
printf("9の個数:%d\n",k);











return 0;
}
