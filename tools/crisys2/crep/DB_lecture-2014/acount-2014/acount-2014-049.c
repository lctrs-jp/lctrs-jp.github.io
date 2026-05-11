#include <stdio.h>

#define SIZE 256
#define ALPHABET 26
#define SMALL_GAP 97
#define BIG_GAP 65

void test(void);
void countCharacter(char str[]);

int main(void)
{
  // test countCharacter()
  test();

  return 0;
}

void test(void)
{
  char string[SIZE];

  printf("input string(shorter than %d): ", SIZE);
  scanf("%s", string);

  countCharacter(string);

  return;
}

void countCharacter(char str[])
{
  int i;
  int count[ALPHABET];
  int freq_num; 

  // initialize
  for(i=0; i<ALPHABET; i++)
    count[i] = 0;

  // count
  for(i=0; str[i]!='\0'; i++)
    if('a' <= str[i] && str[i] <= 'z')
      count[(int)str[i]-SMALL_GAP]++;
    else if('A' <= str[i] && str[i] <= 'Z')
      count[(int)str[i]-BIG_GAP]++;

  // analyze
  freq_num = 0;
  for(i=0; i<ALPHABET; i++)
    if(freq_num < count[i]){
      freq_num = count[i];
    }

  // print result
  printf("most frequent character\t: ");
  for(i=0; i<ALPHABET; i++)
    if(freq_num == count[i])
      printf("%c ", (char)(i+SMALL_GAP));
  printf("\n");
  printf("number to appear\t: %d\n", freq_num);

  return;
}
