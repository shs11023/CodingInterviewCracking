#include <stdio.h>

int p = 2;
int q = 3;
int x = 10000000;
int y = 10000000;

int seq(int n)
{
  if(n <= 0) return 1;

  return seq((n/p)-x) + seq((n/q)-y);
}

int main(void)
{
  printf("seq : %d\n", seq(12));
  return 0;
}
