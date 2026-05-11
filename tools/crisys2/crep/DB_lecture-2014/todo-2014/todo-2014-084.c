#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item[100];

int main(int argc, char *argv[])
{
  FILE *time;
  char str[300], str2[12], str3[7], str4[258], a[6],b[4], c[4], str5[12], *p, *p2, *p3, *p4;
  int n, n2;

  if( argc != 3 ){
    printf("ERROR\n");
    exit(1);
  }

  if(( time = fopen( argv[2], "rb" ) ) == NULL ){
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  n = 0;

  while(!feof(time)){
    str[0] = '\0';
    fgets( str, 298, time );
    n = strlen( str );
    str[n-1] = '\0';

    p = str;
    p2 = str2;

    while( *p && *p != ' ' ){
      *p2 = *p;
      p++;
      p2++;
    }
    *p2 = '\0';
    p++;

    p3 = str3;

    while( *p && *p != ' ' ){
      *p3 =  *p;
      p++;
      p3++;
    }
    *p3 = '\0';
    p++;

    p4 = str4;

    while( *p ){
      *p4 = *p;
      p++;
      p4++;
    }
    *p4 = '\0';

    sscanf( str2, "%d/%d/%d", &item[n].year, &item[n].month, &item[n].day );
    sscanf( str3, "%d:%d", &item[n].hour, &item[n].minute );

    n++;
  }


  str2[0] = '\0';
  sscanf( argv[1], "%s/%s/%s", a, b, c );

  p = str2;
  p2 = a;
  p3 = b;
  p4 = c;

  while( *p2 ){
    *p = *p2;
    p++;
    p2++;
  }

  while( *p3 ){
    *p = *p3;
    p++;
    p3++;
  }

  while( *p4 ){
    *p = *p4;
    p++;
    p4++;
  }

  *p = '\0';


  for( n2 = 0; n2 < n ; n++ ){

    a[0] = '\0';
    b[0] = '\0';
    c[0] = '\0';

    sprintf( a, "%d4", item[n2].year );
    sprintf( b  ,"%2d", item.[n2].month );
    sprintf( c , "%2d", item.[n2].day );

    p = str5;
    p2 = a;
    p3 = b;
    p4 = c;

    while( *p2 ){
      *p = *p2;
      p++;
      p2++;
    }

    while( *p3 ){
      *p = *p3;
      p++;
      p3++;
    }

    while( *p4 ){
      *p = *p4;
      p++;
      p4++;
    }

    *p = '\0';

    if( strcmp( str2, str5 ) <= 0 )
      break;

    n2++;
  }

  while( n2 < n ){
    printf("%4d/%2d/%2d %2d:%.2d %s\n", item[n2].year, item[n2].month, item[n2].day, item[n2].hour, item[n2].minute, item[n2].content );
  }

  return 0;
}
