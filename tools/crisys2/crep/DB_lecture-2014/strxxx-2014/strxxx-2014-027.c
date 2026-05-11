/*mystrcpy*/

void mystrcpy(char trg[], char src[])
{
        int i;

        for( i = 0; src[i] != '\0'; i++ ) {
                trg[i] = src[i];
        }
        trg[i] = '\0';
}

/*mystrcat*/

void mystrcat(char trg[], char src[])
{
        int i;
        int len = strlen( trg );

        for( i = 0; src[i] != '\0'; i++ ) {
                trg[ i + len ] = src[i];
        }
        trg[i + len] = '\0';
}

mystrlen

int mystrlen(char trg[])
{
        int i = 0;

        for( i = 0; trg[i] != '\0'; i++ )
                ;
        return i;
}