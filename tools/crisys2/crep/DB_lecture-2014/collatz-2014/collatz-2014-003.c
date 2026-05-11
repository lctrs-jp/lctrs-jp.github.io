#include <stdio.h>
int one(int n[1000]);
int main()
{
  int n[1000], i;
  scanf("%d", &n[0]);
  for(i=0; n[i]==1; i++) 
    {
      if(n[i]%2 == 1)
	n[i+1] = n[i]*3+1;
      if(0 == n[i]%2)
	n[i+1]=n[i]/2;
      printf("%d\n", n[i]);
    }
  return 0;
}


