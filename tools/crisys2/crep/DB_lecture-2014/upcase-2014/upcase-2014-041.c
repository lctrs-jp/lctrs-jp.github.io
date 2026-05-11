void upcase(char str[])

{
  int i;

  for( i = 0 ; str[i] ! = '\0' ; i++ )
    {
     if ( 'a' <= str[i]  && str[i] <= 'z')
      {
       str[i] = str[i] + ( 'A' - 'a' );
      }  
    }

  return;
}