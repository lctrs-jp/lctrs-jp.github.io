#include <stdio.h>
#include <string.h>
#include <math.h>

int ruijou(int n);

int main(int argc, char *argv[])
{
	int i, j = 0,  ans = 0;
	char str[100];
	int moji[100];
	//argv++;
	
	for(i = 0; i < argc; i++){
		str[i] = *(argv[1] + i);
	}
	
	for(i = 0; str[i] != '\0'; i++){
		moji[i] = str[i] - 64;
	}

	while(str[j]){
		j++;
	}
	
	printf("%d\n", ruijou(0));
	
	
	/*
	for(i = 0; str[i] != '\0'; i++){		
		printf("%c\n", str[i]);
		printf("%d\n", moji[i]);
	}*/
	
	for(i = 0; i < j; i++)
		moji[i] * ruijou(j - i -1);
	
	for(i = 0; str[i] != '\0'; i++)
		ans += moji[i];
	
	printf("%d\n", ans);
	
	//printf("%s\n", argv[1]+1);
	
	
	
	return 0;
}


int ruijou(int n)
{
	int x = 1;
	
    while(n >= 1){
        x *= 26;
    	n--;
    	ruijou(n);
      }
	
	return x;
}