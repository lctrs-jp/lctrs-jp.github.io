#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define PMAX 3//打ち込む人数
#define LMAX 20//ファイル一行の限界

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
}da[MAX];

int main( int argc, char *argv[] )
{
  FILE *fp;
  int len,n,dnum,a,b,p,day,month,year;
  char str[LMAX];
  char str2[LMAX], dateb[LMAX];

  if( argc != 4 ){
    printf("./ex2 ファイル名 ファイル名\n");
    exit(1);
  }

  dnum = 0;

  for( n = 0; n <= PMAX - 1; n++ ){

    if( ( fp = fopen( argv[n+1], "r" ) ) == NULL ){
      printf("ファイルの読み込みに失敗しました。\n");
      exit(1);
    }

    if( fgets( str,LMAX, fp ) != NULL ){
      len = strlen( str );
      if( len > 0 && str[len-1] == '\n' )
	str[len-1] = '\0';
      if( !strcmp( str, "#Alice" ) )
	p = 0;
      else if( !strcmp( str, "#Bob" ))
	p = 1;
      else if( !strcmp( str, "#Carol"))
	p = 2;
      else{
	printf( "ファイルの記述方式に間違いがあります。\n" );
	printf("%s\n", str );
      }
    }
    str[0] = '\0';

    while( fgets( str,LMAX, fp ) != NULL ){
      len = strlen( str );
      if( len > 0 && str[len-1] == '\n' )
	str[len-1] = '\0'; 
      sscanf( str, "%s %c", dateb, str2 );
      for( a = 0; a <= dnum+1; a++ )
	if( !strcmp( dateb, da[a].date ) )
	  if( p == 0 )
	    da[a].alice = str2[0];
	  else if( p == 1 )
	    da[a].bob = str2[0];
	  else if( p == 2 )
	    da[a].carol = str2[0];
	  else if( dnum != 0){
	    dnum++;
	    if( p == 0 )
	      da[dnum].alice = str2[0];
	    else if( p == 1 )
	      da[dnum].bob = str2[0];
	    else if( p == 2 )
	      da[dnum].carol = str2[0];
	    else
	      printf("Error\n");
	  }
	  else
	    if( p == 0 ){
	      da[dnum].alice = str2[0];
	      dnum++;
	    }
	    else if( p == 1 ){
	      da[dnum].bob, str2[0];
	      dnum++;
	    }
	    else if( p == 2 ){
	      da[dnum].carol = str2[0];
	      dnum++;
	    }
	    else
	      printf("Error\n");

      /*
      if( dnum == 0 )
	if( p == 0 )
	  strcpy( da[dnum].alice, str2 );
	else if( p == 1 )
	  strcpy( da[dnum].bob, str2 );
	else if( p == 2 )
	  strcpy( da[dnum].carol, str2 );
	else
	  printf("Error\n");
      */
    }
    fclose(fp);
  }
  /*  printf("%c\n",da[0].alice );*/
  printf("date\t\tAlice\tBob\tCarol\n");

  for( a = 0; a <= dnum; a++ ){

    sscanf( da[a].date, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	 year, month, day,
	 da[a].alice, da[a].bob, da[a].carol );
  }

  return 0;

}


/*
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
 */
