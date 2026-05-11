#include <stdio.h>
#include <string.h>

	// 文字列のコピー
	int mystrcpy(char a[], char b[])
	{
		int i;
		for(i=0; b[i]!='\0'; i++){
			a[i]=b[i];
		}
		a[i]='\0';

	}
// 文字列の長さ
	int mystrlen(char a[])
	{
  		int i = 0;
        for( i = 0; a[i] != '\0'; i++ )
        return i;
	}

	// 文字列の結合
	int mystrcat(char a[], char b[])
	{
		int i;
        int len = mystrlen(a);

        for( i = 0; b[i] != '\0'; i++ ) {
                a[ i + len ] = b[i];
        }
        a[i + len] = '\0';
	}

	

int main(void)
{
	char a[80];
	char b[80];

		int i;
// 長さの確認
	printf("%sは%dの長さ\n",a,mystrlen(a));
	printf("%sは%dの長さ\n",b,mystrlen(b));
// 文字列の比較 
		i=strcmp(a,b);
		if (!i)
		printf("文字列は等しい\n");
		else if(i<0)
		printf("%sは%sより小さい\n",a,b);
		else 
		printf("%sは%sより大きい\n",a,b);

		if ((mystrlen(a)+mystrlen(b))<80){
			mystrcat(a,b);
			printf("%s\n",a);
		}

// bにaをコピー
	mystrcpy(a,b);
	printf("%s %s\n",a,b );


		return 0;
	}
