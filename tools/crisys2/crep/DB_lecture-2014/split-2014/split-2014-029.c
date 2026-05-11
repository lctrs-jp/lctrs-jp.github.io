#include <stdio.h>

int split(char buf[],char *out[]);

int main(void)
{
  char s[100];
  char *t[100];
  int i;
  int num;

  printf("100文字以内の文字列を入力してください。\n");
  fgets(s,100,stdin);

  num=split(s,t);

  printf("入力された文字列を空白で区切ると、%d文に区切られ、その分はこれらです。\n",num);
  for(i=0;i<num;i++)
    printf("%s,",t[i]);

  return 0;
}

//方針としては、ひたすら空白をnullで埋めつつ、空白の次の文字のポインタをひたすらoutに代入していく。
int split(char buf[],char *out[])
{
  int i;
  int j=0; //bufの、最新の空白の次の最初の文字を示す。
  int k=0; //outに順番に入れるために、次に入れるoutを常に指し示す。
  int a=0; //別れた分の個数合計。
  
  for(i=0;buf[i] != '\0';i++)
    {
      if(buf[i]==' ' && buf[i-1]=='\0') //もし空白に連続であたっていた場合、aをカウントせず、jの値を次に合わせて空白をnullで埋める。
	{
	  j=i+1;
	  buf[i]='\0';
	}
      else if(buf[i]==' ') //もし空白にあたった場合、aを挙げて、outにそこまでの文字列をポインタで代入。kのカウントを挙げたのち、jを合わせ、空白を埋める。
	{
	  a++;
	  out[k]=&buf[j];
	  k++;
	  j=i+1;
	  buf[i]='\0';
	}
    }

  //最後に残った分を代入する。
  a++; 
  out[k]=&buf[j];

  return a;
}
      
