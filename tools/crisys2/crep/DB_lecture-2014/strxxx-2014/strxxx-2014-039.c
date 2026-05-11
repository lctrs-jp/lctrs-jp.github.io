#include <stdio.h>

char mystrcpy(char trg1[],char src1[]);
char mystrcat(char trg2[],char src2[]);
int mystrlen(char ch[]);
int mystrcmp(char trg3[],char src3[]);

int main()
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください: ");
  fgets(str1, 80, stdin);
  printf("第二の文字列を入力してください: ");
  fgets(str2, 80, stdin);

  printf("%sは%d文字の長さです\n",str1, mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2, mystrlen(str2));

  i = mystrcmp(str1, str2);
  if (i > 0)
    printf("%sは%sより大きい\n",str1, str2);
  else if (i < 0)
    printf("%sは%sより小さい\n",str1, str2);
  else
    printf("文字列は等しい\n");

  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1, str2);
  printf("%s%s\n",str1, str2);

  return 0;
}

char mystrcpy(char trg1[], char src1[])
{
  int i = 0;
  for (i = 0; trg1[i]! =  '\0';i++) {
    trg1[i] = src1[i];
  }
  return trg1[i];
}
x
char mystrcat(char trg2[],char src2[])
{
  int i, j;
  i = 0;
  j = 0;
  while (trg2[i]! = '\0') {
    i++;
  }
  do {
    trg2[i] = src2[i];
    i++;
    j++;
  } while (trg2[i]! = '\0');
  return trg2[i];
}

int mystrlen(char ch[])
{
  int i;
  i = 0;
  do {
    i++;
  } while (ch[i]! = '\0');
  return i-1;
}

int mystrcmp(char trg3[],char src3[])
{
  int i, j;
  i = 0;
  do {
    if (trg3{i] < src3[i]) {
      j = -1;
      break;
    }
    else if (trg3[i] > src3[i]) {
      j = 1;
      break;
    }
    else
      j = 0;
    i++;
  } while (trg3[i] = src3[i]);
  return j;
}
