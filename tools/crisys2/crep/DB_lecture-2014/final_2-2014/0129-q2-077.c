#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

struct attendance {
  char date; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
  int tugou[3]; //3人の都合
}item[29], *p;


/*int main(){
struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
 int n, year, month, day;
 
 sscanf( item.date, "%d", &n );
 day = n % 100;
 month = (n / 100) % 100;
 year = n / 10000;
 }*/


int main(int argc, char *argv[])
{
  FILE *fp;
  char str[100],*hito[3];
  int i,t=0,len;
  //  printf("a");

  if(argc < 2)
    {
      printf("ファイルを入力してください");
      exit(1);
    }
	
  for(i = 1; i < 4; i++)
    {
      if(strcmp(argv[i], "alice.txt" )== 0 )
	{
	  hito[i - 1] = "Alice";
	}
      else if(strcmp(argv[i], "carol.txt") == 0 )
	{
	  hito[i - 1] = "Carol";
	}
      else if(strcmp(argv[i], "bob.txt") == 0 )
	{
	  hito[i - 1] = "Bob";
	}
    }
  
  for(i = 0; i < 3; i++)
    {
      t = 0;
      p = item;
      
      if((fp = fopen(argv[i+1],"r")) == NULL)
	{
	  printf("%d番目のファイルのオープンに失敗しました",i);
	  exit(1);
	}
      
      fgets(str,100,fp);
      len = strlen(str);
      // if(len > 0 && str[len - 1] == '\n')
      //	len = strlen(str);
      
          while(fgets(str,100,fp) != NULL)
	{
	  len = strlen(str);
	  if(len > 0 && str[len - 1] == '\n')
	    str[len - 1] = '\0';
	  sscanf(str,"%d %c",&item[t].date, &item[t].tugou[i]);
	  	
  //	  day = n % 100;
	  // month = (n / 100) % 100;
	  // year = n / 10000;   
	  t++;
	}
      
      fclose(fp);
    }
  printf("date\t\tAlice\tBob\tCarol\n");
  // for(i=0; i< 12; i++,t++)
  // {
  //  printf("");
  return 0;
}




/*
	  if(str[0] == '\0' || str[0] == '\n')
	    continue;
	  sscanf(str,"%");
	    






int main()
{
  struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  int n, year, month, day;

  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
         year, month, day,
         item.alice, item.bob, item.carol,
         item.ok, item.unfixed );

  return 0;
}
*/
