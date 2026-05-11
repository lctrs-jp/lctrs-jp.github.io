void swapcase(char [i])

{
  int i;

  for ( i=0 ; str[i] ! ='\0' ; i++)
    {
     if ( ( 'A' <= str[i] && str[i]  <= 'Z' )
            || ( 'a' <= str[i] && str[i] <= 'z' )  )
       { 
        if ( 'A' <= str[i]  && str[i] <= 'Z' )
          {
           str[i] = str[i] + ('a' - 'A');
          }
        else 
          { 
           str[i] = str[i] + ('A' - 'a');
          }
       }
    }

  return;
 
}