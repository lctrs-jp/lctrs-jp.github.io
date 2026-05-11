#include<stdio.h>
#include<string.h>
 
void main()
{
  char n[100];
  int i;
  int a, b, c, d, e, f, g, h, l, m;
  a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, l=0, m=0;

  printf("数字列を入力してください(長さ100以下)");
    
  scanf("%s",n );
  
  for(i=0; i<strlen(n); i++){
    if (n[i]=='0')
     a= a+1;
     else
       if (n[i]=='1')
         b= b+1;
         else 
           if (n[i]=='2')
             c= c+1;
             else
               if (n[i]=='3')
                 d= d+1;
                 else
                   if (n[i]=='4')
                     e= e+1;
                     else
                       if (n[i]=='5')
                         f= f+1;
                         else
                           if (n[i]=='6')
                             g= g+1;
                             else
                               if (n[i]=='7')
                                 h= h+1;
                                 else 
                                   if (n[i]=='8')
                                     l= l+1;
                                     else
                                       if (n[i]=='9')
                                         m= m+1; 
  }
  
  printf("0 は%d 個含まれています.\n", a);
  printf("1 は%d 個含まれています.\n", b);
  printf("2 は%d 個含まれています.\n", c);
  printf("3 は%d 個含まれています.\n", d);
  printf("4 は%d 個含まれています.\n", e);
  printf("5 は%d 個含まれています.\n", f);
  printf("6 は%d 個含まれています.\n", g);
  printf("7 は%d 個含まれています.\n", h);
  printf("8 は%d 個含まれています.\n", l);
  printf("9 は%d 個含まれています.\n", m);

  
  return ;
}
