#include <stdio.h>
#include <stdlib.h>

int main(int argr, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  
  if (argr < 3 || argr > 4){	/* 起動時引数の判定 */
    printf("<file name><file name><option>\n");
    exit(1);
  }

  if (argr == 4){
    if (*argv[3] != 'w'){	/* w以外を受け取った時、エラーメッセージを出力 */
      printf("'%s' is undefined as option\n", argv[3]);
      printf("maybe you mean 'w'\n");
      exit(1);
    }
  }
  
  if ((fp1 = fopen(argv[1], "r")) == NULL) { /* コピー元ファイルを開く*/
    printf ("file(%s) can not open\n", argv[1]);
    exit(1);
  }

  if ((fp2 = fopen(argv[2], "r+")) != NULL){ /* コピー先のファイルが存在するか判定、存在したら終了 */
    printf("%s already exists\n", argv[2]);
    exit(1);
  }
  fclose(fp2);
  
  if ((fp2 = fopen(argv[2], "w")) == NULL){ /* 新しいコピー先ファイルを作成 */
    printf("error\n");
    exit(1);
  }
  
  if(argr == 3) {		/* wがない時、標準出力なしでコピー */
    while ((ch = fgetc(fp1)) != EOF){
      if ((fputc(ch, fp2)) == EOF) {
	printf("writing error\n");
	exit(1);
      }
    }
  }else if (*argv[3] == 'w'){	/* wのとき、標準出力し、コピー */
    while ((ch = fgetc(fp1)) != EOF){
      if ((fputc(ch, fp2)) == EOF) {
	printf("writing error\n");
	exit(1);
      }
      putchar(ch);
    }
  }
  
  fclose(fp1);
  fclose(fp2);

  return 0;
}
