#include<stdio.h>

int main()
{ 
  char buf[101];
  int i, j ,cnt[26];
  for ( j = 0 ; j<26 ; j++0 ) cnt[j] = 0;

  printf ("アルファベットを入力してください（長さ100以下）：　");
  fgets (buf , 101, stdio);

  for ( i=0 ; buf [i] ! = "\0" ; i++)
    if ( ( 'A' <= buf[i] && buf[i] <= 'Z' ) || 
         ( 'a' <= buf[i] && buf[i] <= 'z' )  )
	 if  ( 'A' <= buf [i]  && buf[i] <= 'Z' )
           cnt[buf[i] - '0'] ++ ;
         else 
           cnt[ buf[i] + ('A'-'a')-'0'] ++;
    
  