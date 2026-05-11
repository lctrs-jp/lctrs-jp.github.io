#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  if(strlen(argv[1]) == 1)
    printf("%d\n",*(argv[1]) - 64);

  if(strlen(argv[1]) == 2)
    printf("%d\n",(*(argv[1]) - 64) * 26 + *(argv[1] + 1) - 64);

  if(strlen(argv[1]) == 3)
    printf("%d\n",(*(argv[1]) - 64) * 26 * 26 + (*(argv[1] + 1) - 64) * 26 + *(argv[1] + 2) - 64);

  if(strlen(argv[1]) == 4)
    printf("%d\n",(*(argv[1]) - 64) * 26 * 26 * 26 + (*(argv[1] + 1) - 64) * 26 * 26 + (*(argv[1] + 2) - 64) * 26 + *(argv[1] + 3) -64);

  if(strlen(argv[1]) == 5)
    printf("%d\n",(*(argv[1]) - 64) * 26 * 26 * 26 * 26 + (*(argv[1] + 1) - 64) * 26 * 26 * 26 + (*(argv[1] + 2) - 64) * 26 * 26 + (*(argv[1] + 3) - 64) * 26 + *(argv[1] + 4) - 64);

  return 0;
}
