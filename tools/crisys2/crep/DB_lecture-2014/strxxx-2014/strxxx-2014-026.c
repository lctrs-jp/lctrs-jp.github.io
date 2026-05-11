#include<stdio.h>
#include<string.h>


/*プロトタイプ宣言*/
void mystrcpy (char n[] , char m[]);

void mystrcat (char a[] , char b[]);

int mystrlen (char r[]);


int main()

{

  printf("文字列を入力してください\n");

  char  k[20] ;
  fgets(k, 20, stdin);
 char l[100];

 mystrcpy(l, k);
 printf("コピー結果\n");
 printf("%s\n",l);


 printf("文字列を入力してください\n");
 

 char c[10] ;
 gets(c);

 printf("2つ目の文字列を入力してください\n");
 char d[10];
 gets(d);

 mystrcat( c, d);

 printf("つなげた結果は\n");
 printf("%s\n" ,c);



 printf("文字列を入力してください\n");
 char p[20];
 gets(p);

 printf("入力した文字数は");
 printf("%dです\n", mystrlen(p));

 return 0;

   }

 void mystrcpy(char n[] ,char m[])
{

  int s;

  for(s=0; ;s++)
    { n[s]=m[s];
  if(n[s]=='\0')  
    break;
    }

}

void mystrcat(char a[],char b[])
{
  int t,u ;
  
  for(t=0;a[t]!='\0';t++){}
   
  for(u=0;;u++ , t++)
    {a[t]=b[u];
      if(b[u]=='\0')
	break;}
   
}

int mystrlen(char r[])
{
  int i=0;
  for(i=0;r[i]!='\0';i++);
  return i;
}
