#include <string.h>
#include <stdio.h>

int mystrlen ();
int mystrcmp (); 
char mystrcat ();
char mystrcpy ();

int main (void)
{ 
  char str1[80] , str2[80];
  int i;


  printf ("第１の文字列を入力してください:");
  gets ( str1 );
  printf ("第２の文字列を入力してください:");
  gets ( str2 );


  printf ("%s は %d 文字の長さです\n" , str1 , mystrlen ( str1 ) );
  printf ("%s は %d 文字の長さです\n" , str2 , mystrlen ( str2 ) );

  /*
  i = mystrcmp ( str1 , str2 );
  if (!i)
    printf ("文字列は等しい\n ");
  else if ( i < 0 )
    printf ("%s は %s より小さい\n", str1 , str2 );
  else
    printf ("%s は %s より大きい\n", str1 , str2 );
  
  */

  if ( ( mystrlen ( str1 ) + mystrlen ( str2 ) ) < 80 ) {
    strcat ( str1 , str2 );
    printf ("%s\n", str1 );
  }

  
  mystrcpy ( str1, str2 );
  printf ("%s %s\n", str1 , str2 );

   

  return 0;
}



int mystrlen (char trg[] )
{
  int i,len1,len2;
  
  len1 = 0;
  len2 = 0;

  for (i = 0 ; trg[i]!= '\0' ; i++ ){
    if (trg[i]!= '\0')
      len1 = len1 + 1;
      len2 = len2 + 1;
  }  
   
  return i;
}      
              
     
 
char mystrcat (char trg[] , char src[] )
{
  int i;

  for (trg[i]!= '\0'; trg[i] + src[i]!='\0' ; i++ ){
    if (trg[i] + src[i]!='\0')
      trg[i] = src[i];
  }   
   

  return i;
}   



char mystrcpy (char trg[] , char src[] )
{
  int i;

  for (i = 0 ; trg[i]!= '\0' ; i++ ){
    if (trg[i]!= '\0')
      trg[i] = src[i];
  }


  return i;
}  
